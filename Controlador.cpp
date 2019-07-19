/*
 * Controlador.cpp
 *
 *  Created on: 28 oct. 2018
 *      Author: ALBERT AV, GABRIEL ROA
 *      CEDULA: 26710983, 25919459
 */

#include "Controlador.h"
#include "Librerias/Lista.cpp"

void Controlador::IncluirTaquilla(){
	MTaquilla maux;
	Nodo<MTaquilla> *apx;
	Nodo<MZona> *apx2;
	MZona zaux;
	bool si1,si2,si3;
	string ct,zo;
	apx=NULL;
	apx2=NULL;
	vt.Limpiar();
	vt.ImprimirEncabezado("		INCLUIR TAQUILLA","		================");
	ct=vt.LeerString("\n INGRESE EL CODIGO: ");
	do{
		apx=NULL;
		if(ListTaquilla.BuscarTaquilla(maux,ct,apx)){
			vt.ImprimirMensaje("\n ESTA TAQUILLA YA EXISTE...");
			ct=vt.LeerString("\n INGRESE OTRO CODIGO PARA LA TAQUILLA: ");
			si2=true;
		}
		else{
			mt.setCodTaquilla(ct);
			si2=false;
		}
	}while(si2);

	zo=vt.LeerString("\n INGRESE EL CODIGO DE LA ZONA: ");

	do{
		if(ListZona.BuscarZona(zaux,zo,apx2)){
			mt.Vaciar();
			si1=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA ZONA NO EXISTE...");
			zo=vt.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA ZONA: ");
			si1=true;
		}
	}while(si1);

	do{
		if(!ListTaquilla.ContarTaquilla(zo)){
			ListZona.BuscarZona(zaux,zo,apx2);
			mt.setDatosTaquilla(zo,zaux.getPrecio());
			si3=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA ZONA YA TIENE 2 TAQUILLAS ASIGNADAS...");
			zo=vt.LeerString("\n INGRESE EL CODIGO DE OTRA ZONA: ");
			si3=true;
		}
	}while(si3);

	if(ListTaquilla.Vacia()){
		ListTaquilla.InsComienzo(mt);
		ap1=ListTaquilla.ObtPrimero();
	}
	else{
		ListTaquilla.InsDerecho(ap1,mt);
		ap1=ap1->ObtDer();
	}

	vt.ImprimirMensaje("\n TAQUILLA INCLUIDA CON EXITO...");
	vt.Pausa();
	vt.Limpiar();
	vt.ImprimirInformacion(mt.getCodTaquilla(),zaux.getDescrip(),mt.getPrecio(),mt.getPuestosV());
}

void Controlador::ModificarTaquilla(){
	MTaquilla maux;
	MZona zaux;
	Nodo<MTaquilla> *apx;
	Nodo<MZona> *apx2;
	apx=NULL;
	apx2=NULL;
	bool si1,si2,si3;
	string ct,zo;
	vt.Limpiar();
	vt.ImprimirEncabezado("		MODIFICAR DATOS DE LA TAQUILLA","		==============================");
	ct=vt.LeerString("\n INGRESE EL CODIGO DE LA TAQUILLA A MODIFICAR: ");

	do{
		if(ListTaquilla.BuscarTaquilla(maux,ct,apx)){
			si2=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA TAQUILLA NO EXISTE...");
			ct=vt.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA TAQUILLA: ");
			si2=true;
		}
	}while(si2);


	ListZona.BuscarZona(zaux,maux.getzona(),apx2);
	vt.ImprimirInformacion(maux.getCodTaquilla(),zaux.getDescrip(),maux.getPrecio(),maux.getPuestosV());

	zo=vt.LeerString("\n INGRESE EL NUEVO CODIGO DE LA ZONA: ");

	do{
		if(ListZona.BuscarZona(zaux,zo,apx2)){
			mt.Vaciar();
			si1=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA ZONA NO EXISTE...");
			zo=vt.LeerString("\n INGRES DE NUEVO EL CODIGO DE LA ZONA: ");
			si1=true;
		}
	}while(si1);

	do{
		if(!ListTaquilla.ContarTaquilla(zo)){
			ListZona.BuscarZona(zaux,zo,apx2);
			mt.setDatosTaquilla(zo,zaux.getPrecio());
			si3=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA ZONA YA TIENE 2 TAQUILLAS ASIGNADAS...");
			zo=vt.LeerString("\n INGRESE EL CODIGO DE OTRA ZONA: ");
			si3=true;
		}
	}while(si3);

	mz.limpiar();

	if(ListTaquilla.Modificar(apx,maux)){
		vt.ImprimirMensaje("\n TAQUILLA MODIFICADA CON EXITO...");
		ListZona.BuscarZona(zaux,maux.getzona(),apx2);
		vt.ImprimirInformacion(maux.getCodTaquilla(),zaux.getDescrip(),maux.getPrecio(),maux.getPuestosV());
	}
	else{
		vt.ImprimirMensaje("\n ERROR AL MODIFICAR LA TAQUILLA...");
	}
	vt.Limpiar();
}

void Controlador::EliminarTaquilla(){
	MTaquilla maux;
	MZona zaux;
	Nodo<MTaquilla> *apx,*an;
	Nodo<MZona> *apx2;
	apx=NULL;
	an=NULL;
	apx2=NULL;
	bool si2;
	string ct;
	int resp;
	vt.Limpiar();
	vt.ImprimirEncabezado("		ELIMINAR TAQUILLA","		=================");
	ct=vt.LeerString("\n INGRESE EL CODIGO DE LA TAQUILLA A ELIMINAR: ");

	do{
		if(ListTaquilla.BuscarTaquilla(maux,ct,apx)){
			si2=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA TAQUILLA NO EXISTE...");
			ct=vt.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA TAQUILLA: ");
			si2=true;
		}
	}while(si2);

	ListZona.BuscarZona(zaux,maux.getzona(),apx2);
	vt.ImprimirInformacion(maux.getCodTaquilla(),zaux.getDescrip(),maux.getPrecio(),maux.getPuestosV());

	resp=vt.LeerNro("\n SEGURO QUE DESEA ELIMINAR LA TAQUILLA [1] SI [2] NO: ");

	if(resp==1){
		if(ListTaquilla.BuscarAntTaquilla(maux.getCodTaquilla(),an)){
			ListTaquilla.Eliminar(apx,maux,an);
			vt.ImprimirMensaje("\n TAQUILLA ELIMINADA CON EXITO...");
			vt.ImprimirInformacion(maux.getCodTaquilla(),zaux.getDescrip(),maux.getPrecio(),maux.getPuestosV());
		}
		else{
			vt.ImprimirMensaje("\n ERROR AL ELIMINAR LA TAQUILLA...");
		}
	}

	vt.Limpiar();
}

void Controlador::IncluirZona(){
	MZona zaux;
	Nodo<MZona> *apx;
	apx=NULL;
	bool si;
	string ds,cd;
	float pr;
	int cp;
	vz.Limpiar();
	vz.ImprimirEncabezado("		INCLUIR ZONA","		============");
	cd=vz.LeerString("\n INGRESE EL CODIGO: ");

	do{
		if(ListZona.BuscarZona(zaux,cd,apx)){
			vt.ImprimirMensaje("\n ESTA ZONA YA EXISTE...");
			cd=vt.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA ZONA: ");
			si=true;
		}
		else{
			mz.Vaciar();
			mz.setCodigo(cd);
			si=false;
		}
	}while(si);

	ds=vz.LeerString("\n INGRESE LA DESCRIPCION: ");
	pr=vz.LeerNroDecimal("\n INGRESE EL PRECIO DE LOS BOLETOS: BsS. ");
	cp=vz.LeerNro("\n INGRESE LA CANTIDAD DE ASIENTOS: ");
	mz.setDatos(ds,pr,cp);

	if(ListZona.Vacia()){
		ListZona.InsComienzo(mz);
		ap2=ListZona.ObtPrimero();
	}
	else{
		ListZona.InsDerecho(ap2,mz);
		ap2=ap2->ObtDer();
	}

	vt.ImprimirMensaje("\n ZONA INCLUIDA CON EXITO...");
	vt.Pausa();
	vt.Limpiar();
	vz.ImprimirZona(mz.getDescrip(),mz.getCodigo(),mz.getPrecio(),mz.getCantPues());
}

void Controlador::ModificarZona(){
	MZona zaux;
	Nodo<MZona> *apx;
	apx=NULL;
	bool si;
	string ds,cd;
	float pr;
	int cp;
	vz.Limpiar();
	vz.ImprimirEncabezado("		MODIFICAR ZONA","		==============");
	cd=vz.LeerString("\n INGRESE EL CODIGO DE LA ZONA A MODIFICAR: ");

	do{
		if(ListZona.BuscarZona(zaux,cd,apx)){
			si=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA ZONA NO EXISTE...");
			cd=vt.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA ZONA: ");
			si=true;
		}
	}while(si);

	ds=vz.LeerString("\n INGRESE LA DESCRIPCION: ");
	pr=vz.LeerNroDecimal("\n INGRESE EL PRECIO DE LOS BOLETOS: BsS. ");
	cp=vz.LeerNro("\n INGRESE LA CANTIDAD DE ASIENTOS: ");

	zaux.Vaciar();
	zaux.setDatos(ds,pr,cp);

	if(ListZona.Modificar(apx,zaux)){
		vt.ImprimirMensaje("\n ZONA MODIFICADA CON EXITO...");
		vz.ImprimirZona(zaux.getDescrip(),zaux.getCodigo(),zaux.getPrecio(),zaux.getCantPues());
	}
	else{
		vt.ImprimirMensaje("\n ERROR AL MODIFICAR LA ZONA...");
	}
	vt.Limpiar();
}

void Controlador::EliminarZona(){
	MZona zaux;
	Nodo<MZona> *apx,*an;
	apx=NULL;
	an=NULL;
	bool si;
	string cd;
	int resp;
	vz.Limpiar();
	vz.ImprimirEncabezado("		ELIMINAR ZONA","		=============");
	cd=vz.LeerString("\n INGRESE EL CODIGO DE LA ZONA A ELIMINAR: ");

	do{
		if(ListZona.BuscarZona(zaux,cd,apx)){
			si=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA ZONA NO EXISTE...");
			cd=vt.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA ZONA: ");
			si=true;
		}
	}while(si);

	vz.ImprimirZona(zaux.getDescrip(),zaux.getCodigo(),zaux.getPrecio(),zaux.getCantPues());

	resp=vt.LeerNro("\n SEGURO QUE DESEA ELIMINAR LA ZONA [1] SI [2] NO: ");

	if(resp==1){
		if(ListZona.BuscarAntZona(zaux.getCodigo(),an)){
			ListZona.Eliminar(apx,zaux,an);
			vz.ImprimirZona(zaux.getDescrip(),zaux.getCodigo(),zaux.getPrecio(),zaux.getCantPues());
			vt.ImprimirMensaje("\n ZONA ELIMINADA CON EXITO...");
		}

		else{
			vt.ImprimirMensaje("\n ERROR AL ELIMINAR LA ZONA...");
		}
	}
	vt.Limpiar();
}

void Controlador::ProcesarVenta(MTaquilla mt1, Nodo<MTaquilla> *ap){
	MZona zaux;
	Nodo<MZona> *apx;
	string cd,nom;
	int cp,cpd;
	bool si;
	vt.Limpiar();
	vc.ImprimirEncabezado("		VENTA DE BOLETOS","		================");
	MCliente c;

	do {
		cd=vc.LeerString("\n INGRESE LA CEDULA DEL CLIENTE: ");
		if (!mt1.buscarCliente(cd,c)){
			vc.ImprimirMensaje("\n CLIENTE NO ENCONTRADO EN LA TAQUILLA...");
			int resp;
			resp = vc.LeerValidarNro("\n ¿DESEA INCLUIRLO? [1] SI [2] NO: ",1,2);
			if (resp==1)
				IncluirClienteTaquilla(mt1, ap, cd, c);
			else {
				c.SetCedula(cd);
				break;
			}
		}
	} while (c.GetCedula()=="-1");

	ListZona.BuscarZona(zaux,mt1.getzona(),apx);
	cpd=zaux.PuestosDisponibles();

	cp=vc.LeerNro("\n INGRESE EL NRO DE BOLETOS A VENDER: ");
	do{
		if(cp>cpd){
			si=true;
			vc.ImprimirMensaje("\n LA CANTIDAD DE BOLETOS ES SUPERIOR A \n LA CANTIDAD DE BOLETOS DISPONIBLES EN LA ZONA...\n");
			cp=vc.LeerNro("\n INGRESE DE NUEVO EL NRO DE BOLETOS A VENDER: ");
		}
		else
			si=false;
	}while(si);

	c.setCantAsien(cp);
	mt1.PuestosV(cp);
	MBoleto b;
	for (int i=0;i<c.getCantAsien();i++){
		int nro = vc.LeerValidarNroValorInicial("\n INTRODUZCA EL NRO DEL ASIENTO DESEADO: ",1);
		b.setCodZona(mt1.getzona());
		b.setNroAsiento(nro);
		c.incluirBoletos(b);
	}

	c.CalcularMonto(mt1.getPrecio());
	mt1.incluirCliente(c);
	vc.ImprimirFactura(c.GetCedula(),c.GetNombre(),c.getCantAsien(),c.Monto());

	ListTaquilla.Modificar(ap,mt1);
	zaux.PuestosVendidos(cp);
	ListZona.Modificar(apx,zaux);
	vc.Limpiar();
}

void Controlador::IncluirClienteTaquilla(){
	MTaquilla maux;
	Nodo<MTaquilla> *apx;
	apx=NULL;
	bool si2;
	string ct,zo;
	vt.Limpiar();
	vt.ImprimirEncabezado("		INCLUIR CLIENTE EN LA TAQUILLA","		==============================");
	ct=vt.LeerString("\n INTRODUZCA EL CODIGO DE LA TAQUILLA A INCLUIR: ");

	do{
		if(ListTaquilla.BuscarTaquilla(maux,ct,apx)){
			si2=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA TAQUILLA NO EXISTE...");
			ct=vt.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA TAQUILLA: ");
			si2=true;
		}
	}while(si2);

	MCliente c;
	string ced, nom, dir, tlf;
	ced = vc.LeerString(" INTRODUZA LA CEDULA DEL CLIENTE: ");
	nom = vc.LeerString(" INTRODUZA EL NOMBRE DEL CLIENTE: ");
	dir = vc.LeerString(" INTRODUZA LA DIRECCION DEL CLIENTE: ");
	tlf = vc.LeerString(" INTRODUZA EL NRO DE TELEFONO DEL CLIENTE: ");
	c.SetCedula(ced);
	c.SetNombre(nom);
	c.SetDir(dir);
	c.SetTlf(tlf);
	maux.incluirCliente(c);

	if(ListTaquilla.Modificar(apx,maux)){
		vt.ImprimirMensaje("\n CLIENTE INCLUIDO CON EXITO...");
	}
	else{
		vt.ImprimirMensaje("\n ERROR INCLUYENDO AL CLIENTE...");
	}
	vt.Pausa();
	vt.Limpiar();
}

void Controlador::IncluirClienteTaquilla(MTaquilla mt1, Nodo<MTaquilla> *ap, string cedula, MCliente &c){
	string nom, dir, tlf;
	nom = vc.LeerString(" INTRODUZA EL NOMBRE DEL CLIENTE: ");
	dir = vc.LeerString(" INTRODUZA LA DIRECCION DEL CLIENTE: ");
	tlf = vc.LeerString(" INTRODUZA EL NRO DE TELEFONO DEL CLIENTE: ");
	c.SetCedula(cedula);
	c.SetNombre(nom);
	c.SetDir(dir);
	c.SetTlf(tlf);
	mt1.incluirCliente(c);
	ListTaquilla.Modificar(ap, mt1);
}

void Controlador::ConsularTaquilla(){
	MTaquilla maux;
	Nodo<MTaquilla> *apx;
	MZona zaux;
	Nodo<MZona> *apx2;
	apx2=NULL;
	apx=NULL;
	bool si;
	string ct;
	vt.Limpiar();
	vt.ImprimirEncabezado("		DATOS DE LA TAQUILLA","		====================");
	ct=vt.LeerString("\n INGRESE EL CODIGO DE LA TAQUILLA: ");

	do{
		if(ListTaquilla.BuscarTaquilla(maux,ct,apx)){
			si=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA TAQUILLA NO EXISTE...");
			ct=vt.LeerNro("\n INGRESE DE NUEVO EL CODIGO DE LA TAQUILLA: ");
			si=true;
		}
	}while(si);

	ListZona.BuscarZona(zaux,maux.getzona(),apx2);
	vt.ImprimirInformacion(maux.getCodTaquilla(),zaux.getDescrip(),maux.getPrecio(),maux.getPuestosV());
	vt.Limpiar();
}

void Controlador::ConsularZona(){
	MZona zaux;
	Nodo<MZona> *apx;
	apx=NULL;
	bool si;
	string cd;
	vz.Limpiar();
	vz.ImprimirEncabezado("		DATOS DE LA ZONA","		================");
	cd=vz.LeerString("\n INGRESE EL CODIGO DE LA ZONA: ");
	do{
		if(ListZona.BuscarZona(zaux,cd,apx)){
			si=false;
		}
		else{
			vz.ImprimirMensaje("\n ESTA ZONA NO EXISTE...");
			cd=vz.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA ZONA: ");
			si=true;
		}
	}while(si);
	vz.ImprimirZona(zaux.getDescrip(),zaux.getCodigo(),zaux.getPrecio(),zaux.getCantPues());
	vz.Limpiar();
}

void Controlador::Inicio(){
	MTaquilla mt1;
	Nodo<MTaquilla> *apu;
	string cdt;
	int opc;
	bool re;
	apu=NULL;

	do{
		vt.Limpiar();
		vt.ImprimirEncabezado("		BOLETERIA CARDENALES","		====================");
		vt.ImprimirMensaje("\n 1. VENDER BOLETOS ");
		vt.ImprimirMensaje("\n 2. GESTIONAR ");
		vt.ImprimirMensaje("\n 3. CONSULAR ");
		vt.ImprimirMensaje("\n 4. RESPORTES ");
		vt.ImprimirMensaje("\n\n 5. SALIR DEL SISTEMA ");
		opc=vt.LeerValidarNro("\n INDIQUE SU OPCION: ",1,5);
		switch(opc){
			case 1:{
					do{
						vt.Limpiar();
						cdt=vt.LeerString("\n INGRESE EL CODIGO DE LA TAQUILLA: ");
						if(ListTaquilla.BuscarTaquilla(mt1,cdt,apu)){
							ProcesarVenta(mt1,apu);
							re=false;
						}
						else{
							vt.ImprimirMensaje("\n ESA TAQUILLA NO EXISTE \n");
							re=true;
						}
					}while(re);
			}
				break;

			case 2: Gestionar();
				break;
			case 3: Consultar();
				break;
			case 4: Reportes();
				break;
		}
	}while(opc!=5);
}

void Controlador::Consultar(){
	int opc;
	do{
		vt.Limpiar();
		vt.ImprimirEncabezado("		BOLETERIA CARDENALES","		====================");
		vt.ImprimirMensaje("\n 1. CONSULTAR ZONA ");
		vt.ImprimirMensaje("\n 2. CONSULTAR TAQUILLA ");
		vt.ImprimirMensaje("\n 3. CONSULTAR BOLETOS DE UN CLIENTE ");
		vt.ImprimirMensaje("\n\n 4. VOLVER AL INICIO ");
		opc=vt.LeerValidarNro("\n\n INDIQUE SU OPCION: ",1,4);
		switch(opc){
			case 1: ConsularZona();
				break;
			case 2: ConsularTaquilla();
				break;
			case 3: ConsultarBoletosCliente();
				break;
			case 4: Inicio();
				break;
		}
	}while(opc!=5);

}

void Controlador::Gestionar(){
	int opc;

	do{
		vt.Limpiar();
		vt.ImprimirEncabezado("		BOLETERIA CARDENALES","		====================");
		vt.ImprimirMensaje("\n 1. INCLUIR ZONA ");
		vt.ImprimirMensaje("\n 2. INCLUIR TAQUILLA ");
		vt.ImprimirMensaje("\n 3. INCLUIR CLIENTE ");
		vt.ImprimirMensaje("\n 4. MODIFICAR ZONA ");
		vt.ImprimirMensaje("\n 5. MODIFICAR TAQUILLA ");
		vt.ImprimirMensaje("\n 6. ELIMINAR ZONA ");
		vt.ImprimirMensaje("\n 7. ELIMINAR TAQUILLA ");
		vt.ImprimirMensaje("\n\n 8. VOLVER AL INICIO ");
		opc=vt.LeerValidarNro("\n\n INDIQUE SU OPCION: ",1,8);
		switch(opc){
			case 1: IncluirZona();
				break;
			case 2: IncluirTaquilla();
				break;
			case 3: IncluirClienteTaquilla();
				break;
			case 4: ModificarZona();
				break;
			case 5: ModificarTaquilla();
				break;
			case 6: EliminarZona();
				break;
			case 7: EliminarTaquilla();
				break;
			case 8: Inicio();
				break;
		}
	}while(opc!=9);
}

void Controlador::CargarDatos(){
	vt.Limpiar();
	vt.ImprimirEncabezado("		BIENVENIDO USUARIO","		==================");
	vt.ImprimirMensaje("\n ANTES DE COMENZAR LLENA LOS DATOS SIGUIENTES....");
	vt.ImprimirMensaje("\n NOTA: SON 5 ZONAS Y 2 TAQUILLAS POR ZONAS COMO DATOS INICIALES.... COMENZEMOS");
	vt.Pausa();
	vt.Limpiar();

	for(int i=0;i<2;i++){
		IncluirZona();
	}

	for(int i=0;i<4;i++){
		IncluirTaquilla();
	}
}

void Controlador::Reportes(){
	int opc;
	do{
		vt.Limpiar();
		vt.ImprimirEncabezado("		BOLETERIA CARDENALES","		====================");
		vt.ImprimirMensaje("\n 1. REPORTE GENERAL ");
		vt.ImprimirMensaje("\n 2. REPORTE ZONA ");
		vt.ImprimirMensaje("\n 3. REPORTE TAQUILLA ");
		vt.ImprimirMensaje("\n\n 4. VOLVER AL INICIO ");
		opc=vt.LeerValidarNro("\n\n INDIQUE SU OPCION: ",1,4);
		switch(opc){
			case 1:ReporteGeneral();
				break;
			case 2: ReporteZona();
				break;
			case 3: ReporteTaquilla();
				break;
			case 4: Inicio();
				break;
		}
	}while(opc!=5);
}

void Controlador::ReporteTaquilla(){
	MTaquilla maux;
	MCliente mcaux;
	Nodo<MTaquilla> *apx;
	apx=NULL;
	bool si;
	string ct;
	vt.Limpiar();
	vt.ImprimirEncabezado("		DATOS DE LA TAQUILLA","		====================");
	ct=vt.LeerString("\n INGRESE EL CODIGO DE LA TAQUILLA: ");

	do{
		if(ListTaquilla.BuscarTaquilla(maux,ct,apx)){
			si=false;
		}
		else{
			vt.ImprimirMensaje("\n ESTA TAQUILLA NO EXISTE...");
			ct=vt.LeerNro("\n INGRESE DE NUEVO EL CODIGO DE LA TAQUILLA: ");
			si=true;
		}
	}while(si);

	vt.Limpiar();

	mcaux=maux.MayorVenta();
	vt.ImprimirReporte(maux.getCodTaquilla(),maux.getPuestosV(),maux.CalcularGancia(),mcaux.Monto(),mcaux.GetCedula(),mcaux.GetNombre());
	vt.Limpiar();
}

void Controlador::ReporteZona(){
	MZona zaux;
	MTaquilla taux;
	Nodo<MZona> *apx;
	apx=NULL;
	bool si;
	string cd;
	vz.Limpiar();
	vz.ImprimirEncabezado("		DATOS DE LA ZONA","		================");
	cd=vz.LeerString("\n INGRESE EL CODIGO DE LA ZONA: ");
	do{
		if(ListZona.BuscarZona(zaux,cd,apx)){
			si=false;
		}
		else{
			vz.ImprimirMensaje("\n ESTA ZONA NO EXISTE...");
			cd=vz.LeerString("\n INGRESE DE NUEVO EL CODIGO DE LA ZONA: ");
			si=true;
		}
	}while(si);

	vz.Limpiar();

	ListTaquilla.TaquillaMayorXZona(zaux.getCodigo(),taux);
	vz.ImprimirReporte(zaux.getDescrip(), zaux.GananciaTotal(), taux.CalcularGancia(),zaux.PuestosDisponibles(), taux.getCodTaquilla());
	vz.Limpiar();
}

void Controlador::ReporteGeneral(){
	MZona zaux;
	MTaquilla taux;
	MTaquilla maux;
	MCliente mcaux;

	vz.Limpiar();

	ListZona.ZonaMayor(zaux);
	ListTaquilla.TaquillaMayorXZona(zaux.getCodigo(),taux);
	vz.ImprimirReporte(zaux.getDescrip(), zaux.GananciaTotal(), taux.CalcularGancia(),zaux.PuestosDisponibles(), taux.getCodTaquilla());

	ListTaquilla.TaquillaMayor(maux);
	mcaux=maux.MayorVenta();
	vt.ImprimirReporte(maux.getCodTaquilla(),maux.getPuestosV(),maux.CalcularGancia(),mcaux.Monto(),mcaux.GetCedula(),mcaux.GetNombre());

	vz.Limpiar();
}

void Controlador::ConsultarBoletosCliente(){
	MTaquilla maux;
	MCliente caux;
	MZona zaux;
	Nodo <MTaquilla> *apux1;
	Nodo <MZona> *apux;
	apux1=NULL;
	apux=NULL;
	bool noencontrado = true;
	bool pv = true; //Si es primer boleto que se encuentra en la taquilla, imprime el código
	Pila<MBoleto> pilaux;
	MBoleto bolaux;
	int tbt = 0; //Total de Boletos por Taquilla
	int tbc = 0; //Total de Boletos del Cliente
	string ced;
	vz.ImprimirEncabezado("\n CONSULTAR BOLETOS COMPRADOS"," POR UN CLIENTE");
	ced = vz.LeerString("\n INTRODUZCA LA CÉDULA DEL CLIENTE A CONSULTAR: ");
	apux1=ListTaquilla.ObtPrimero();

	while(apux1!=NULL) {
		maux=apux1->ObtInfo();
		tbt = 0;
		if (maux.buscarCliente(ced,caux)){
			noencontrado = false;
			while (!caux.boletosCliente.Vacia()){
				if (pv){
					vz.ImprimirString("\n\n CÓDIGO DE LA TAQUILLA: ",maux.getCodTaquilla());
					vz.ImprimirString("\n NOMBRE DEL CLIENTE EN TAQUILLA: ",caux.GetNombre());
					ListZona.BuscarZona(zaux,maux.getzona(),apux);
					vz.ImprimirString("\n ZONA: ",zaux.getDescrip());
					vz.ImprimirMensaje("\n NÚMEROS DE ASIENTOS COMPRADOS: ");
					caux.boletosCliente.Remover(bolaux);
					vz.ImprimirNro("",bolaux.getNroAsiento());
					tbt++;
					pilaux.Insertar(bolaux);
					pv=false;
				} else {
					caux.boletosCliente.Remover(bolaux);
					vz.ImprimirNro(", ",bolaux.getNroAsiento());
					tbt++;
					pilaux.Insertar(bolaux);
				}
			}
			if (!pilaux.Vacia()){
				pilaux.Remover(bolaux);
				caux.boletosCliente.Insertar(bolaux);
			}
			if (tbt!=0) vz.ImprimirNro("\n\n CANTIDAD DE BOLETOS COMPRADOS EN LA TAQUILLA: ",tbt);
			tbc+=tbt;
			pv=true;
		}
		apux1=apux1->ObtDer();
	}

	if (noencontrado){
		vz.ImprimirMensaje("\n CLIENTE NO ENCONTRADO");
	} else if (tbc==0){
		vz.ImprimirMensaje("\n EL CLIENTE NO HA COMPRADO BOLETOS AÚN");
	} else {
		vz.ImprimirNro("\n\n CANTIDAD TOTAL DE BOLETOS COMPRADOS POR EL CLIENTE: ",tbc);
	}
	vt.Pausa();
	pilaux.Tope=NULL;
}

Controlador::Controlador(){
	ap1=NULL;
	ap2=NULL;
}

Controlador::~Controlador(){
	 Nodo<MTaquilla> *p;
	 while (!ListTaquilla.Vacia())
	 {
	     p=ap1->ObtDer();
	     delete ap1;
	     ap1=p;
	}
	Nodo<MZona> *p2;
	while (!ListTaquilla.Vacia())
	{
		p2=ap2->ObtDer();
	 	delete ap2;
	 	ap2=p2;
	}
}
