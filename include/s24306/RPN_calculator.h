#include <memory>
#include <queue>
#include <stack>


namespace student { namespace rpn_calculator{
using stack_type = std::stack<double>;

struct Element{
    virtual auto evaluate(stack_type&) const -> void = 0;
    virtual ~Element();
};

struct Literal : public Element{
    double const value{0.0};

    auto evaluate(stack_type&) const -> void override;

    Literal(double const);
};

struct Print : public Element{
    auto evaluate(stack_type&) const -> void override;
};

struct Addition : public Element{
    auto evaluate(stack_type&) const -> void override;
};

struct Calculator{
    stack_type stack;
    std::queue<std::unique_ptr<Element>> ops;

    auto push(std::unique_ptr<Element>) -> void;
    auto push(std::string) -> void;
    auto evaluate() -> void;

    Calculator() = default;
    Calculator(stack_type);
};
}}
