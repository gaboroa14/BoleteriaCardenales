/*
 * Controlador.h
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_
#include "Librerias/Lista.h"
#include "ModelosCliente/MCliente.h"
#include "ModelosTaquilla/MTaquilla.h"
#include "ModelosTaquilla/MZona.h"
#include "ModelosTaquilla/MBoleto.h"
#include "Vistas/VCliente.h"
#include "Vistas/VTaquilla.h"
#include "Vistas/VZona.h"

class Controlador {
private:
	MCliente mc;
	MTaquilla mt;
	MZona mz;
	VCliente vc;
	VTaquilla vt;
	VZona vz;
	Nodo<MTaquilla> *ap1;
	Nodo<MZona> *ap2;
public:
	Lista<MTaquilla> ListTaquilla;
	Lista<MZona> ListZona;
	Controlador();
	void Inicio();
	void IncluirTaquilla();
	void IncluirZona();
	void ModificarTaquilla();
	void ModificarZona();
	void EliminarTaquilla();
	void EliminarZona();
	void ConsularTaquilla();
	void ConsularZona();
	void ProcesarVenta(MTaquilla mt1, Nodo<MTaquilla> *ap);
	void IncluirClienteTaquilla();
	void IncluirClienteTaquilla(MTaquilla mt1, Nodo<MTaquilla> *ap, string cedula, MCliente &c);
	void Consultar();
	void Reportes();
	void Gestionar();
	void CargarDatos();
	void ReporteTaquilla();
	void ReporteZona();
	void ReporteGeneral();
	void ConsultarBoletosCliente();
	~Controlador();
};


#endif /* CONTROLADOR_H_ */
