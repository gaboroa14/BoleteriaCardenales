/*
 * VTaquilla.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: Scorpion
 */

#include "VTaquilla.h"

VTaquilla::VTaquilla() {

}
void VTaquilla::ImprimirInformacion(string cd, string zo, float ps, int pv){
	Limpiar();
	ImprimirEncabezado("		TAQUILLA: "+cd,"		=============");
	ImprimirString("\n ZONA: ", zo);
	ImprimirNroDecimal("\n PRECIO DE BOLETOS: ", ps);
	ImprimirNro("\n CANTIDAD DE PUESTOS VENDIDOS: ", pv);
	Pausa();
}

void VTaquilla::ImprimirReporte(string cd, int pv, float gn, float mv, string ced,string nom){
	ImprimirEncabezado("\n\n		TAQUILLA: "+cd,"		=============");
	ImprimirNro("\n CANTIDAD DE PUESTOS VENDIDOS: ", pv);
	ImprimirNroDecimal("\n GANANCIA DE LA TAQUILLA: BsS. ", gn);
	ImprimirNroDecimal("\n MAYOR VENTA: BsS. ", mv);
	ImprimirString("\n CEDULA DEL CLIENTE: ", ced);
	ImprimirString("\n NOMBRE DEL CLIENTE: ", nom);
	Pausa();
}
