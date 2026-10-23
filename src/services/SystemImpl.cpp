
#include "../../include/services/SystemImpl.h"


int SystemImpl::obtenerIndiceDepto(DepartamentoAVL* departamentos, const string& nombre) {
        for (int i = 0; i < NUM_DEPARTAMENTOS; i++) {
        if (departamentos[i].nombre == nombre) {
            return i;
        }
    }
    return -1;
}

void SystemImpl::registrarPacienteEnServicio(DepartamentoAVL* departamentos, Paciente* p, const string& servicio) {

    int idx = obtenerIndiceDepto(departamentos, servicio);
    if (idx != -1) {
        departamentos[idx].arbol->insertar(p);
    }
}

bool SystemImpl::buscarEnArbolRecursivo(NodoAVL<Paciente*>* nodo, const string& query, string& ruta, Paciente*& pacienteEncontrado) {
    if (nodo == nullptr) return false;

    string currentIdStr = to_string(nodo->getDato()->getId());
    if (nodo->getDato()->getId() < 10) currentIdStr = "0" + currentIdStr;

    string rutaActual = ruta + currentIdStr + " ";

    if (to_string(nodo->getDato()->getId()) == query || currentIdStr == query || nodo->getDato()->getNombre() == query) {
        pacienteEncontrado = nodo->getDato();
        ruta = rutaActual;
        return true;
    }

    if (buscarEnArbolRecursivo(nodo->getIzquierdo(), query, rutaActual, pacienteEncontrado)) {
        ruta = rutaActual;
        return true;
    }

    if (buscarEnArbolRecursivo(nodo->getDerecho(), query, rutaActual, pacienteEncontrado)) {
        ruta = rutaActual;
        return true;
    }

    return false;
}

ResultadoBusqueda SystemImpl::buscarPaciente(DepartamentoAVL* departamentos, const string& query) {
       ResultadoBusqueda resultado = {false, nullptr, "", ""};

        for (int i = 0; i < NUM_DEPARTAMENTOS; i++) {
                string ruta = "";
                Paciente* p = nullptr;

                if (buscarEnArbolRecursivo(departamentos[i].arbol->getRaiz(), query, ruta, p)) {
                        resultado.encontrado = true;
                        resultado.paciente = p;
                        resultado.departamento = departamentos[i].nombre;
                        resultado.ruta = ruta;
                        break;
                    }
            }
        return resultado;
    }


void SystemImpl::cargarFila(List<Paciente *>* datos, Queue<Paciente *>* fila) {
    if (datos == nullptr || fila == nullptr) {
        return;
    }

    for (int i = 0; i < datos->getSize(); i++) {
        fila->push(datos->get(i));
    }

}




ArbolDecision* SystemImpl::buildArbolDecision() {

    // Hojas de Urgencia: una por cada ruta.
    Condicion urgencia1; urgencia1.servicio = "Urgencia";
    Condicion urgencia2; urgencia2.servicio = "Urgencia";
    Condicion urgencia3; urgencia3.servicio = "Urgencia";
    Condicion urgencia4; urgencia4.servicio = "Urgencia";
    Condicion urgencia5; urgencia5.servicio = "Urgencia";

    BTNode<Condicion>* hojaUrgencia1 = new BTNode<Condicion>(urgencia1);
    BTNode<Condicion>* hojaUrgencia2 = new BTNode<Condicion>(urgencia2);
    BTNode<Condicion>* hojaUrgencia3 = new BTNode<Condicion>(urgencia3);
    BTNode<Condicion>* hojaUrgencia4 = new BTNode<Condicion>(urgencia4);
    BTNode<Condicion>* hojaUrgencia5 = new BTNode<Condicion>(urgencia5);

    // Hojas de los demás servicios.
    Condicion cirugia; cirugia.servicio = "Cirugia";
    Condicion pediatria; pediatria.servicio = "Pediatria";
    Condicion cardiologia; cardiologia.servicio = "Cardiologia";
    Condicion neurologia; neurologia.servicio = "Neurologia";
    Condicion traumatologia; traumatologia.servicio = "Traumatologia";
    Condicion traumatologia2; traumatologia2.servicio = "Traumatologia";
    Condicion hospitalizacion; hospitalizacion.servicio = "Hospitalizacion";
    Condicion medicinaGeneral; medicinaGeneral.servicio = "Medicina General";

    BTNode<Condicion>* hojaCirugia = new BTNode<Condicion>(cirugia);
    BTNode<Condicion>* hojaPediatria = new BTNode<Condicion>(pediatria);
    BTNode<Condicion>* hojaCardiologia = new BTNode<Condicion>(cardiologia);
    BTNode<Condicion>* hojaNeurologia = new BTNode<Condicion>(neurologia);
    BTNode<Condicion>* hojaTraumatologia = new BTNode<Condicion>(traumatologia);
    BTNode<Condicion>* hojaTraumatologia2 = new BTNode<Condicion>(traumatologia2);
    BTNode<Condicion>* hojaHospitalizacion = new BTNode<Condicion>(hospitalizacion);
    BTNode<Condicion>* hojaMedicinaGeneral = new BTNode<Condicion>(medicinaGeneral);

    // Condiciones de urgencia.
    Condicion c1(Atributo::DOLOR, "8", "Dolor >= 8?",
                 Operador::MAYOR_IGUAL, true);
    Condicion c2(Atributo::PRESION_SISTOLE, "180",
                 "Presion sistolica >= 180?",
                 Operador::MAYOR_IGUAL, true);
    Condicion c3(Atributo::PRESION_DIASTOLE, "120",
                 "Presion diastolica >= 120?",
                 Operador::MAYOR_IGUAL, true);
    Condicion c4(Atributo::TEMPERATURA, "35",
                 "Temperatura < 35?", Operador::MENOR, true);
    Condicion c5(Atributo::TEMPERATURA, "40",
                 "Temperatura > 40?", Operador::MAYOR, true);

    BTNode<Condicion>* n1 = new BTNode<Condicion>(c1);
    BTNode<Condicion>* n2 = new BTNode<Condicion>(c2);
    BTNode<Condicion>* n3 = new BTNode<Condicion>(c3);
    BTNode<Condicion>* n4 = new BTNode<Condicion>(c4);
    BTNode<Condicion>* n5 = new BTNode<Condicion>(c5);

    n1->setLeft(hojaUrgencia1);
    n1->setRight(n2);

    n2->setLeft(hojaUrgencia2);
    n2->setRight(n3);

    n3->setLeft(hojaUrgencia3);
    n3->setRight(n4);

    n4->setLeft(hojaUrgencia4);
    n4->setRight(n5);

    n5->setLeft(hojaUrgencia5);

    // Cirugía.
    Condicion c6(Atributo::REQUIERE_CIRUGIA, "true",
                 "Requiere cirugia == true?", Operador::IGUAL);
    BTNode<Condicion>* n6 = new BTNode<Condicion>(c6);

    n5->setRight(n6);
    n6->setLeft(hojaCirugia);

    // Pediatría.
    Condicion c7(Atributo::EDAD, "18", "Edad < 18?",
                 Operador::MENOR, true);
    BTNode<Condicion>* n7 = new BTNode<Condicion>(c7);

    n6->setRight(n7);
    n7->setLeft(hojaPediatria);

    // Cardiología.
    Condicion c8(Atributo::TIPO_DOLOR, "pecho",
                 "Tipo de dolor == pecho?", Operador::IGUAL);
    BTNode<Condicion>* n8 = new BTNode<Condicion>(c8);

    n7->setRight(n8);
    n8->setLeft(hojaCardiologia);

    // Dolor de cabeza.
    Condicion c11(Atributo::TIPO_DOLOR, "cabeza",
                  "Tipo de dolor == cabeza?", Operador::IGUAL);
    BTNode<Condicion>* n11 = new BTNode<Condicion>(c11);

    n8->setRight(n11);

    // Síntomas neurológicos.
    Condicion c12(Atributo::SINTOMAS_NEUROLOGICOS, "true",
                  "Sintomas neurologicos == true?", Operador::IGUAL);
    BTNode<Condicion>* n12 = new BTNode<Condicion>(c12);

    n11->setLeft(n12);
    n12->setLeft(hojaNeurologia);

    // Trauma tras dolor de cabeza sin síntomas neurológicos.
    Condicion c14(Atributo::TRAUMA, "true",
                  "Trauma == true?", Operador::IGUAL);
    BTNode<Condicion>* n14 = new BTNode<Condicion>(c14);

    n12->setRight(n14);
    n14->setLeft(hojaTraumatologia);

    // Dolor de extremidad.
    Condicion c13(Atributo::TIPO_DOLOR, "extremidad",
                  "Tipo de dolor == extremidad?", Operador::IGUAL);
    BTNode<Condicion>* n13 = new BTNode<Condicion>(c13);

    n11->setRight(n13);

    // Trauma para el caso de dolor de extremidad.
    Condicion c14b(Atributo::TRAUMA, "true",
                   "Trauma == true?", Operador::IGUAL);
    BTNode<Condicion>* n14b = new BTNode<Condicion>(c14b);

    n13->setLeft(n14b);
    n14b->setLeft(hojaTraumatologia2);

    // Condición de días de hospitalización.
    Condicion c15(Atributo::DIAS_HOSPITALIZACION, "2",
                  "Dias hospitalizacion >= 2?",
                  Operador::MAYOR_IGUAL, true);

    // Rama de hospitalización tras dolor de cabeza.
    BTNode<Condicion>* n15 = new BTNode<Condicion>(c15);

    n14->setRight(n15);
    n15->setLeft(hojaHospitalizacion);
    n15->setRight(hojaMedicinaGeneral);

    // Rama de hospitalización tras dolor de extremidad y trauma.
    BTNode<Condicion>* n15b = new BTNode<Condicion>(c15);

    n14b->setRight(n15b);

    Condicion hospitalizacion2;
    hospitalizacion2.servicio = "Hospitalizacion";
    BTNode<Condicion>* hojaHospitalizacion2 =
        new BTNode<Condicion>(hospitalizacion2);

    Condicion medicinaGeneral2;
    medicinaGeneral2.servicio = "Medicina General";
    BTNode<Condicion>* hojaMedicinaGeneral2 =
        new BTNode<Condicion>(medicinaGeneral2);

    n15b->setLeft(hojaHospitalizacion2);
    n15b->setRight(hojaMedicinaGeneral2);

    // Rama de hospitalización cuando el dolor no es de extremidad.
    BTNode<Condicion>* n15c = new BTNode<Condicion>(c15);

    n13->setRight(n15c);

    Condicion hospitalizacion3;
    hospitalizacion3.servicio = "Hospitalizacion";
    BTNode<Condicion>* hojaHospitalizacion3 =
        new BTNode<Condicion>(hospitalizacion3);

    Condicion medicinaGeneral3;
    medicinaGeneral3.servicio = "Medicina General";
    BTNode<Condicion>* hojaMedicinaGeneral3 =
        new BTNode<Condicion>(medicinaGeneral3);

    n15c->setLeft(hojaHospitalizacion3);
    n15c->setRight(hojaMedicinaGeneral3);

    return new ArbolDecision(n1);
}


