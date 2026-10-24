
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


void SystemImpl::buildArbolDecision(ArbolDecision* arbol) {

    // Hojas de Urgencia.
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
    Condicion pediatria; pediatria.servicio = "Pediatria";
    Condicion cirugia; cirugia.servicio = "Cirugia";
    Condicion cardiologia; cardiologia.servicio = "Cardiologia";
    Condicion neurologia; neurologia.servicio = "Neurologia";
    Condicion traumatologia; traumatologia.servicio = "Traumatologia";

    BTNode<Condicion>* hojaPediatria = new BTNode<Condicion>(pediatria);
    BTNode<Condicion>* hojaCirugia = new BTNode<Condicion>(cirugia);
    BTNode<Condicion>* hojaCardiologia = new BTNode<Condicion>(cardiologia);
    BTNode<Condicion>* hojaNeurologia = new BTNode<Condicion>(neurologia);
    BTNode<Condicion>* hojaTraumatologia = new BTNode<Condicion>(traumatologia);

    // Hojas independientes de Hospitalización y Medicina General.
    Condicion hospitalizacion1; hospitalizacion1.servicio = "Hospitalizacion";
    Condicion hospitalizacion2; hospitalizacion2.servicio = "Hospitalizacion";
    Condicion hospitalizacion3; hospitalizacion3.servicio = "Hospitalizacion";

    Condicion medicinaGeneral1; medicinaGeneral1.servicio = "Medicina General";
    Condicion medicinaGeneral2; medicinaGeneral2.servicio = "Medicina General";
    Condicion medicinaGeneral3; medicinaGeneral3.servicio = "Medicina General";

    BTNode<Condicion>* hojaHospitalizacion1 = new BTNode<Condicion>(hospitalizacion1);
    BTNode<Condicion>* hojaHospitalizacion2 = new BTNode<Condicion>(hospitalizacion2);
    BTNode<Condicion>* hojaHospitalizacion3 = new BTNode<Condicion>(hospitalizacion3);

    BTNode<Condicion>* hojaMedicinaGeneral1 = new BTNode<Condicion>(medicinaGeneral1);
    BTNode<Condicion>* hojaMedicinaGeneral2 = new BTNode<Condicion>(medicinaGeneral2);
    BTNode<Condicion>* hojaMedicinaGeneral3 = new BTNode<Condicion>(medicinaGeneral3);

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

    // Pediatría.
    Condicion c6(Atributo::EDAD, "18", "Edad < 18?",
                 Operador::MENOR, true);

    BTNode<Condicion>* n6 = new BTNode<Condicion>(c6);

    n5->setRight(n6);
    n6->setLeft(hojaPediatria);

    // Cirugía.
    Condicion c7(Atributo::REQUIERE_CIRUGIA, "true",
                 "Requiere cirugia == true?", Operador::IGUAL);

    BTNode<Condicion>* n7 = new BTNode<Condicion>(c7);

    n6->setRight(n7);
    n7->setLeft(hojaCirugia);

    // Cardiología.
    Condicion c8(Atributo::TIPO_DOLOR, "pecho",
                 "Tipo de dolor == pecho?", Operador::IGUAL);

    BTNode<Condicion>* n8 = new BTNode<Condicion>(c8);

    n7->setRight(n8);
    n8->setLeft(hojaCardiologia);

    // Dolor de cabeza.
    Condicion c9(Atributo::TIPO_DOLOR, "cabeza",
                 "Tipo de dolor == cabeza?", Operador::IGUAL);

    BTNode<Condicion>* n9 = new BTNode<Condicion>(c9);

    n8->setRight(n9);

    // Síntomas neurológicos.
    Condicion c10(Atributo::SINTOMAS_NEUROLOGICOS, "true",
                  "Sintomas neurologicos == true?", Operador::IGUAL);

    BTNode<Condicion>* n10 = new BTNode<Condicion>(c10);

    n9->setLeft(n10);
    n10->setLeft(hojaNeurologia);

    // Hospitalización después de dolor de cabeza sin síntomas neurológicos.
    Condicion c11(Atributo::DIAS_HOSPITALIZACION, "2",
                  "Dias hospitalizacion >= 2?",
                  Operador::MAYOR_IGUAL, true);

    BTNode<Condicion>* n11 = new BTNode<Condicion>(c11);

    n10->setRight(n11);
    n11->setLeft(hojaHospitalizacion1);
    n11->setRight(hojaMedicinaGeneral1);

    // Dolor de extremidad.
    Condicion c12(Atributo::TIPO_DOLOR, "extremidad",
                  "Tipo de dolor == extremidad?", Operador::IGUAL);

    BTNode<Condicion>* n12 = new BTNode<Condicion>(c12);

    n9->setRight(n12);

    // Trauma para dolor de extremidad.
    Condicion c13(Atributo::TRAUMA, "true",
                  "Trauma == true?", Operador::IGUAL);

    BTNode<Condicion>* n13 = new BTNode<Condicion>(c13);

    n12->setLeft(n13);
    n13->setLeft(hojaTraumatologia);

    // Hospitalización después de dolor de extremidad sin trauma.
    Condicion c14(Atributo::DIAS_HOSPITALIZACION, "2",
                  "Dias hospitalizacion >= 2?",
                  Operador::MAYOR_IGUAL, true);

    BTNode<Condicion>* n14 = new BTNode<Condicion>(c14);

    n13->setRight(n14);
    n14->setLeft(hojaHospitalizacion2);
    n14->setRight(hojaMedicinaGeneral2);

    // Hospitalización para los demás tipos de dolor.
    Condicion c15(Atributo::DIAS_HOSPITALIZACION, "2",
                  "Dias hospitalizacion >= 2?",
                  Operador::MAYOR_IGUAL, true);

    BTNode<Condicion>* n15 = new BTNode<Condicion>(c15);

    n12->setRight(n15);
    n15->setLeft(hojaHospitalizacion3);
    n15->setRight(hojaMedicinaGeneral3);

    // Asignar la raíz al árbol existente.
    if (arbol != nullptr) {
        arbol->setRaiz(n1);
    }
}




