#ifndef NODO_H
#define NODO_H

class Nodo{
  public:
    void setVisitantes(int cantidad);
    int getVisitantes();

  protected:
    int visitantes;
};

#endif // NODO_H
