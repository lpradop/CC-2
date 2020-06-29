#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <utility>

class OperationTemplate {
 public:
  using Arguments = std::map<std::string, std::string>;
  bool Solve(const Arguments &input, Arguments &output) {
    assert(output.empty());

    if (!ReadInput(input)) {
      return false;
    }
    if (!Operate()) {
      return false;
    }
    WriteOutput(output);

    return true;
  }
  virtual ~OperationTemplate() {}

 protected:
  virtual bool ReadInput(const Arguments &input) = 0;
  virtual bool Operate() = 0;
  virtual void WriteOutput(Arguments &output) const = 0;
};

class MathOperation : public OperationTemplate {
 private:
  int x_, y_, result_;
  char operation_;
  bool ReadInput(const Arguments &input) {
    Arguments::const_iterator i = input.find("x");
    if (input.end() == i) {
      return false;
    }
    std::istringstream in(i->second);
    in >> x_;
    if (in.fail()) {
      return false;
    }

    i = input.find("y");
    if (input.end() == i) {
      return false;
    }
    in.clear();
    in.str(i->second);
    in >> y_;
    if (in.fail()) {
      return false;
    }

    i = input.find("operation");
    if (input.end() == i || i->second.size() != 1) {
      return false;
    }
    operation_ = i->second[0];

    return true;
  }

  bool Operate() {
    switch (operation_) {
      case '+':
        result_ = x_ + y_;
        break;
      case '-':
        result_ = x_ - y_;
        break;
      case '*':
        result_ = x_ * y_;
        break;
      case '/':
        if (0 == y_) {
          return false;
        }
        result_ = x_ / y_;
        break;
      default:
        return false;
    }

    return true;
  }

  void WriteOutput(Arguments &output) const {
    std::ostringstream out;
    out << result_;
    output.insert(std::make_pair(std::string("result"), out.str()));
  }

 public:
  MathOperation() : x_(0), y_(0), operation_(0), result_(0) {}
};

class ListOperation : public OperationTemplate {
 private:
  std::list<int> list_;

  bool ReadInput(const Arguments &input) {
    list_.clear();
    Arguments::const_iterator i = input.find("array");
    if (input.end() == i) {
      return false;
    }
    std::istringstream in(i->second);
    using T = std::istream_iterator<int>;
    std::copy(T(in), T(), std::back_inserter(list_));
    if (!in.eof()) return false;
    return true;
  }

  bool Operate() {
    list_.reverse();
    return true;
  }

  void WriteOutput(Arguments &output) const {
    std::ostringstream out;
    std::copy(list_.begin(), list_.end(), std::ostream_iterator<int>(out, " "));
    output.insert(std::make_pair(std::string("result"), out.str()));
  }
};

int main() {
  std::map<std::string, std::string> my_input;
  std::map<std::string, std::string> my_output;

  // 10 + 20 = 30
  my_input.insert(std::make_pair("x", "10"));
  my_input.insert(std::make_pair("y", "20"));
  my_input.insert(std::make_pair("operation", "+"));
  MathOperation math_op;
  math_op.Solve(my_input, my_output);
  std::cout << my_output["result"] << std::endl;

  my_input.clear();
  my_output.clear();

  // 1 2 3 4 5 -> 5 4 3 2 1
  my_input["array"] = "1 2 3 4 5";
  ListOperation list_op;
  list_op.Solve(my_input, my_output);
  std::cout << my_output["result"] << std::endl;

  return 0;
}