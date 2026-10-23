//
// Created by Alan Galleguillos on 23-10-2026.
//



// Constructor
template <typename T>
ArbolAVL<T>::ArbolAVL(int (*comparador)(T, T)) {
       raiz = nullptr;
        this->comparador = comparador;
    }

template <typename T>
int ArbolAVL<T>::comparar(T a, T b) {
      if (comparador != nullptr)
                return comparador(a, b);
        if (a < b) return -1;
        if (a > b) return 1;
        return 0;
    }


template<typename T>
NodoAVL<T> *ArbolAVL<T>::getRaiz() {
    return this->raiz;
}

// Destructor
template <typename T>
ArbolAVL<T>::~ArbolAVL() {
    destruirArbol(raiz);
}

template <typename T>
void ArbolAVL<T>::destruirArbol(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        destruirArbol(nodo->getIzquierdo());
        destruirArbol(nodo->getDerecho());
        delete nodo;
    }
}

template <typename T>
int ArbolAVL<T>::max(int a, int b) {
    return (a > b) ? a : b;
}

template <typename T>
int ArbolAVL<T>::obtenerAltura(NodoAVL<T>* nodo) {
    if (nodo == nullptr)
        return 0;
    return nodo->getAltura();
}

template <typename T>
int ArbolAVL<T>::obtenerFactorBalance(NodoAVL<T>* nodo) {
    if (nodo == nullptr)
        return 0;
    return obtenerAltura(nodo->getIzquierdo()) - obtenerAltura(nodo->getDerecho());
}


template <typename T>
NodoAVL<T>* ArbolAVL<T>::rotacionDerecha(NodoAVL<T>* y) {
    NodoAVL<T>* x = y->getIzquierdo();
    NodoAVL<T>* T2 = x->getDerecho();

    x->setDerecho(y);
    y->setIzquierdo(T2);

    y->setAltura(max(obtenerAltura(y->getIzquierdo()), obtenerAltura(y->getDerecho())) + 1);
    x->setAltura(max(obtenerAltura(x->getIzquierdo()), obtenerAltura(x->getDerecho())) + 1);

    return x;
}

template <typename T>
NodoAVL<T>* ArbolAVL<T>::rotacionIzquierda(NodoAVL<T>* x) {
    NodoAVL<T>* y = x->getDerecho();
    NodoAVL<T>* T2 = y->getIzquierdo();

    y->setIzquierdo(x);
    x->setDerecho(T2);

    x->setAltura(max(obtenerAltura(x->getIzquierdo()), obtenerAltura(x->getDerecho())) + 1);
    y->setAltura(max(obtenerAltura(y->getIzquierdo()), obtenerAltura(y->getDerecho())) + 1);

    return y;
}


template <typename T>
NodoAVL<T>* ArbolAVL<T>::insertarRecursivo(NodoAVL<T>* nodo, T valor) {
    if (nodo == nullptr)
        return new NodoAVL<T>(valor);

    int cmp = comparar(valor, nodo->getDato());
        if (cmp < 0) {
            nodo->setIzquierdo(insertarRecursivo(nodo->getIzquierdo(), valor));
        }
       else if (cmp > 0) {
           nodo->setDerecho(insertarRecursivo(nodo->getDerecho(), valor));
       }
       else return nodo;

    nodo->setAltura(1 + max(obtenerAltura(nodo->getIzquierdo()), obtenerAltura(nodo->getDerecho())));

    int balance = obtenerFactorBalance(nodo);


    if (balance > 1 && comparar(valor, nodo->getIzquierdo()->getDato()) < 0)
        return rotacionDerecha(nodo);

    if (balance < -1 && comparar(valor, nodo->getDerecho()->getDato()) > 0)
        return rotacionIzquierda(nodo);

    if (balance > 1 && comparar(valor, nodo->getIzquierdo()->getDato()) > 0) {
        nodo->setIzquierdo(rotacionIzquierda(nodo->getIzquierdo()));
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && comparar(valor, nodo->getDerecho()->getDato()) < 0) {
        nodo->setDerecho(rotacionDerecha(nodo->getDerecho()));
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

template <typename T>
void ArbolAVL<T>::insertar(T valor) {
    raiz = insertarRecursivo(raiz, valor);
}


template <typename T>
void ArbolAVL<T>::inOrdenRecursivo(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        inOrdenRecursivo(nodo->getIzquierdo());
        std::cout << nodo->getDato() << " (Altura: " << nodo->getAltura() << ") " << std::endl;
        inOrdenRecursivo(nodo->getDerecho());
    }
}

template <typename T>
void ArbolAVL<T>::mostrarInOrden() {
    std::cout << "--- Arbol AVL in-orden ---" << std::endl;
    inOrdenRecursivo(raiz);
    std::cout << "--------------------------" << std::endl;
}
template <typename T>
void ArbolAVL<T>::preOrdenRecursivo(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->getDato() << " (Altura: " << nodo->getAltura() << ") " << std::endl;
        preOrdenRecursivo(nodo->getIzquierdo());
        preOrdenRecursivo(nodo->getDerecho());
    }
}

template <typename T>
void ArbolAVL<T>::mostrarPreOrden() {
    std::cout << "--- Arbol AVL pre-orden ---" << std::endl;
    preOrdenRecursivo(raiz);
    std::cout << "---------------------------" << std::endl;
}

template <typename T>
void ArbolAVL<T>::postOrdenRecursivo(NodoAVL<T>* nodo) {
    if (nodo != nullptr) {
        postOrdenRecursivo(nodo->getIzquierdo());
        postOrdenRecursivo(nodo->getDerecho());
        std::cout << nodo->getDato() << " (Altura: " << nodo->getAltura() << ") " << std::endl;
    }
}

template <typename T>
void ArbolAVL<T>::mostrarPostOrden() {
    std::cout << "--- Arbol AVL post-orden ---" << std::endl;
    postOrdenRecursivo(raiz);
    std::cout << "----------------------------" << std::endl;
}

