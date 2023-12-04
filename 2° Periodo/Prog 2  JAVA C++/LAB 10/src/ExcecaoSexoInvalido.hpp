#ifndef EXCECAOSEXOINVALIDO_HPP
#define EXCECAOSEXOINVALIDO_HPP
#include <stdexcept>

using namespace std;

class ExcecaoSexoInvalido : public runtime_error {
public:
    ExcecaoSexoInvalido(string mensagem = "Sexo inválido. Favor digitar M ou F") : runtime_error(mensagem) {}
};

#endif
