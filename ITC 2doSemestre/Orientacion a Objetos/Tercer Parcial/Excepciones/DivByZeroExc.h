#include <stdexcept>

class DivByZeroExc : public std::runtime_error{
  public:
    DivByZeroExc():std::runtime_error{" intento de dividir entre cero "}{}
};