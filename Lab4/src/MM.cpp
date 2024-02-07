#include "MM.h"
#include "Monstruo.h"

MM::MM(int id) {
    this->id = id;
}

bool MM::verificarTipo(Monstruo * monstruo) {
    // retorna true si el monstruo es del mismo tipo que la manada
    // falso en caso contrario
    if (!this->miembros.empty()) {
        return typeid(*this->miembros[0]) == typeid(*monstruo);
    }
    // caso del que el vector este vacio
    // devolvemos true porque si se peude agregar el minstruo al arreglo
    return true;
}

void MM::agregarMiembro(Monstruo * monstruo) {
    if (this->verificarTipo(monstruo)) {
        this->miembros.push_back(monstruo);
        monstruo->setPtrManada(this);
    }
}

void MM::quitarMiembro(Monstruo * monstruo) {
    if (!this->miembros.empty()) {
        int i = 0;
        while (this->miembros[i] != monstruo) {
            i++;
        }
        
        monstruo->nullManada();

        // cout << this->miembros[0]->toString();
        this->miembros[i] = nullptr;
        this->miembros.shrink_to_fit();
        this->miembros.erase(this->miembros.begin() + i);

    }
}

int MM::atacar(Agente * agente) {
    int sum = 0;
    if (!this->miembros.empty()) {
        for (int i = 0; i < this->miembros.size(); ++i) {
            sum += this->miembros[i]->getDanyo();
            this->miembros[i]->atacar(agente);
        }

    }
    return sum;
}

string MM::toString() {

    string respuesta = "Manada {" + std::to_string(this->getCurrentID()) + "}"; 
    if(this->miembros.empty()){
      return respuesta + " vacia";
    }
    respuesta += " compuesta de " + std::to_string(this->miembros.size()) + " monstruos de tipo " + this->miembros[0]->pertenencia();
    

    return respuesta;
}


string MM::pertenencia() {
    if (!this->miembros.empty()) {
        return string("Manada de tipo ") + this->miembros[0]->pertenencia();
    }
    return "Manada vacía";
}

void MM::setAtrapado() {
    if (!this->miembros.empty()) {
        for (int i = this->miembros.size()-1; i > -1; --i) {
            this->miembros[i]->setAtrapado();
        }
    }
}

void MM::entregarMensaje(string mensaje, int id) {
    for (int i = 0; i < miembros.size(); ++i) {
        if (miembros[i]->getCurrentID() != id) {
            miembros[i]->recibirMensaje(mensaje);
        }
    }
}
