#include"empleados.h"
#include"puestos.h"
#include"clientes.h"
#include "Productos.h"
#include "marcas.h"
#include "compra.h"
#include "proveedores.h"
#include "Compras.h"
#include <wingdi.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <tchar.h>
#include<Windows.h>

using namespace std;

void menu_principal();
void menu_empleados();
void menu_puestos();
void menu_clientes();
void menu_marcas();
void menu_productos();
void menu_compras();
void eliminar();
//void menu_ventas();
void menu_proveedores();

//void facturacion();

int main() {

	menu_principal();
	return 0;
	//a.Crear_factura();

}
int no_factura = 0;
int variable = 0;
int id_Ventas = 9;
int id_Producto = 0;

char cadena[] = "ABCDE";


void menu_principal() {


	int opc;
	do {
		cout << "\t\t -------------- Menu Principal ----------------" << endl;
		cout << "\t 1. Tabla de Empleados" << endl;
		cout << "\t 2. Tabla de Puestos" << endl;
		cout << "\t 3. Tabla de Clientes" << endl;
		cout << "\t 4. Tabla de Marcas" << endl;
		cout << "\t 5. Tabla de Productos" << endl;
		cout << "\t 6. Tabla de Proovedores" << endl;
		cout << "\t 7. Tabla de Ventas" << endl;
		cout << "\t 8. Tabla de Compras" << endl;
		cout << "\t 9. Facturacion" << endl;
		cout << "\t 0. Salir" << endl;
		cout << "\t Seleccione su opcion: " << endl;
		cin >> opc;

		system("cls");
		switch (opc) {
		case 1:
			system("cls");
			menu_empleados();
			system("pause>nul");
			break;

		case 2:
			system("cls");
			menu_puestos();
			system("pause>nul");
			break;

		case 3:
			system("cls");
			menu_clientes();
			system("pause>nul");
			break;

		case 4:
			system("cls");
			menu_marcas();
			system("pause>nul");
			break;

		case 5:
			system("cls");
			menu_productos();
			system("pause>nul");
			break;

		case 6:
			system("cls");
			menu_proveedores();
			system("pause>nul");
			break;

		case 7:
			system("cls");
			//menu_ventas();
			system("pause>nul");
			break;

		case 8:
			system("cls");
			menu_compras();
			system("pause>nul");
			break;

		case 9:
			system("cls");
			//facturacion();
			system("pause>nul");
			break;

		case 0:
			opc = false;
			break;

		}
	} while (opc);
}

//empleados
void menu_empleados() {
	system("cls");
	int opcion;
	cout << "-------------- Menu Empleados: ----------------" << endl;
	cout << " 1. Crear....." << endl;
	cout << " 2. Leer....." << endl;
	cout << " 3. Modificar..." << endl;
	cout << " 4. Eliminar..." << endl;
	cout << " 0. Menu Principal..." << endl;
	cout << " Seleccione su opcion: " << endl;
	cin >> opcion;
	system("cls");
	switch (opcion) {

	case 1: {


		cout << " para insertar......." << endl;
		string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso;
		int telefono;
		cin.ignore();
		cout << " ingrese nombres: ";
		getline(cin, nombres);
		cout << " ingrese apellidos: ";
		getline(cin, apellidos);
		cout << " ingrese direccion: ";
		getline(cin, direccion);
		cout << " ingrese telefono :";
		cin >> telefono;
		cin.ignore();
		cout << " ingrese DPI : ";
		getline(cin, DPI);
		cout << " ingrese genero [0=M/1=F]: ";
		getline(cin, genero);
		cout << " ingrese la fecha de nacimiento [AAAA-MM-DD]: ";
		getline(cin, fecha_nacimiento);
		puestos p = puestos();
		p.leer();
		cout << " ingrese el id de puestos : ";
		getline(cin, id_Puestos);
		cout << " ingrese la fecha de inicio de labores [AAAA-MM-DD]: " << endl;
		getline(cin, fecha_inicio_labores);


		empleados e = empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso);

		e.crear();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		empleados e = empleados();

		e.leer();
		system("pause");
		system("cls");
		break;

	}
	case 3: {
		cout << " para modificar......." << endl;
		string nombres, apellidos, direccion, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso;
		int telefono;
		cin.ignore();
		cout << " ingrese nombres modificados: ";
		getline(cin, nombres);
		cout << " ingrese apellidos modificados: ";
		getline(cin, apellidos);
		cout << " ingrese direccion modificada: ";
		getline(cin, direccion);
		cout << " ingrese telefono modificado:";
		cin >> telefono;
		cin.ignore();
		cout << " ingrese DPI modificado: ";
		getline(cin, DPI);
		cout << " ingrese genero modificado [0=M/1=F]: ";
		getline(cin, genero);
		cout << " ingrese fecha de nacimiento modificada[AAAA-MM-DD]: ";
		getline(cin, fecha_nacimiento);
		puestos p = puestos();
		p.leer();
		cout << " ingrese  id del puesto modificado: ";
		getline(cin, id_Puestos);
		cout << " ingrese fecha de inicio de labores modificada [AAAA-MM-DD]: " << endl;
		getline(cin, fecha_inicio_labores);
		cout << " ingrese fecha y hora de ingreso modificada [AAAA-MM-DD  HH:MM:SS]: " << endl;
		getline(cin, fecha_ingreso);



		empleados e = empleados(nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_Puestos, fecha_inicio_labores, fecha_ingreso);
		e.leer();
		e.modificar();
		system("cls");
		system("pause");
		e.leer();
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		empleados e = empleados();
		e.leer();
		e.eliminar();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;
	}
	}
}

//puesto
void menu_puestos() {
	int opcion;
	cout << "-------------- Menu Puestos: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";

	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		cout << " para ingresar......." << endl;

		string Puesto;
		cin.ignore();
		cout << " ingrese puesto: ";
		getline(cin, Puesto);
		puestos p = puestos(Puesto);

		p.crear();
		system("pause");
		system("cls");
		break;

	}

	case 2: {

		string Puesto;
		puestos p = puestos(Puesto);

		p.leer();
		system("pause");
		system("cls");
		break;

	}

	case 3: {
		cout << " para modificar......." << endl;
		string Puesto;
		cin.ignore();
		cout << " ingrese puesto modificado: ";
		getline(cin, Puesto);
		puestos p = puestos(Puesto);

		p.leer();
		p.modificar();
		system("cls");
		system("pause");
		p.leer();
		system("pause");
		system("cls");
		break;
	}

	case 4: {
		string Puesto;
		puestos p = puestos(Puesto);
		p.leer();
		p.eliminar();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;

	}

	}
}

//clientes
void menu_clientes() {
	int opcion;
	cout << "-------------- Menu Clientes: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";


	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		string nombres, apellidos, NIT, genero, correo_electronico, fecha_ingreso;
		int telefono = 0;
		cout << " ingrese nombres: " << endl;
		cin >> nombres;
		cout << " ingrese apellidos: " << endl;
		cin >> apellidos;
		cout << " ingrese direccion: " << endl;
		cin >> NIT;
		cout << " ingrese genero [0=M/1=F] : " << endl;
		cin >> genero;
		cout << " ingrese telefono :" << endl;
		cin >> telefono;
		cout << " ingrese correo electronico: " << endl;
		cin >> correo_electronico;


		clientes c = clientes(nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);

		c.crear();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		string nombres, apellidos, nit, genero, telefono, correo_electronico, fecha_ingreso;
		clientes c = clientes();
		c.leer();
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		string nombres, apellidos, NIT, genero, correo_electronico, fecha_ingreso;
		int telefono = 0;
		cout << " ingrese nombres modificados: " << endl;
		cin >> nombres;
		cout << " ingrese apellidos modificados: " << endl;
		cin >> apellidos;
		cout << " ingrese direccion modificada: " << endl;
		cin >> NIT;
		cout << " ingrese genero modificado [0=M/1=F]: " << endl;
		cin >> genero;
		cout << " ingrese telefono modificado:" << endl;
		cin >> telefono;
		cout << " ingrese correo electronico modificado: " << endl;
		cin >> correo_electronico;
		cout << " ingrese la fecha ingreso modificada: " << endl;
		cin >> fecha_ingreso;


		clientes c = clientes(nombres, apellidos, NIT, genero, telefono, correo_electronico, fecha_ingreso);
		c.leer();
		c.modificar();
		system("cls");
		system("pause");
		c.leer();
		system("cls");
		break;
	}
	case 4: {
		clientes c = clientes();

		c.leer();
		c.eliminar();
		system("pause");
		system("cls");
		break;
	}



	}
}

//marcas
void menu_marcas() {
	int opcion;
	cout << "-------------- Menu Marcas: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";


	cin >> opcion;
	system("cls");
	switch (opcion) {
	case 1: {

		cout << " para ingresar......." << endl;

		string Marca;
		cin.ignore();
		cout << " ingrese Marca: ";
		getline(cin, Marca);
		marcas m = marcas(Marca);

		m.crear();
		system("pause");
		system("cls");
		break;

	}

	case 2: {

		string Marca;
		marcas m = marcas(Marca);

		m.leer();
		system("pause");
		system("cls");
		break;

	}

	case 3: {
		cout << " para modificar......." << endl;
		string Marca;
		cin.ignore();

		cout << " ingrese marca: ";
		getline(cin, Marca);
		marcas m = marcas(Marca);

		m.leer();
		m.modificar();
		system("cls");
		system("pause");
		m.leer();
		system("pause");
		system("cls");
		break;
	}

	case 4: {
		string Marca;
		marcas m = marcas(Marca);
		m.leer();
		m.eliminar();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;

	}

	}

}

//productos
void menu_productos() {
	system("cls");
	int opcion;
	cout << "-------------- Menu Productos: ----------------" << endl;
	cout << " 1. Crear....." << endl;
	cout << " 2. Leer....." << endl;
	cout << " 3. Modificar..." << endl;
	cout << " 4. Eliminar..." << endl;
	cout << " 0. Menu Principal..." << endl;
	cout << " Seleccione su opcion: " << endl;
	cin >> opcion;
	switch (opcion) {

	case 1: {


		cout << " para insertar......." << endl;
		string product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
		cin.ignore();
		cout << " ingrese producto: ";
		getline(cin, product);
		marcas m = marcas();
		m.leer();
		cout << " ingrese id marca: ";
		getline(cin, id_Marca);
		cout << " ingrese descripcion: ";
		getline(cin, descripcion);
		cout << " ingrese imagen: ";
		getline(cin, imagen);
		cout << " ingrese el precio_costo: ";
		getline(cin, precio_costo);
		cout << " ingrese el precio_venta: ";
		getline(cin, precio_venta);
		cout << " ingrese la existencia:";
		getline(cin, existencia);



		Productos pr = Productos(product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
		pr.crear();
		system("pause");
		system("cls");
		break;
	}
	case 2: {
		Productos pr = Productos();

		pr.leer();
		system("pause");
		system("cls");
		break;

	}
	case 3: {
		cout << " para modificar......." << endl;
		string product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;
		cin.ignore();
		cout << " ingrese producto modificado: ";
		getline(cin, product);
		marcas m = marcas();
		m.leer();
		cout << " ingrese id marca modificado: ";
		getline(cin, id_Marca);
		cout << " ingrese descripcion modificada: ";
		getline(cin, descripcion);
		cout << " ingrese imagen modificada: ";
		getline(cin, imagen);
		cout << " ingrese el precio_costo modificado: ";
		getline(cin, precio_costo);
		cout << " ingrese el precio_venta modificado: ";
		getline(cin, precio_venta);
		cout << " ingrese la existencia modificada: ";
		getline(cin, existencia);
		cout << " ingrese fecha y hora de ingreso modificada [AAAA-MM-DD  HH:MM:SS]: " << endl;
		getline(cin, fecha_ingreso);



		Productos pr = Productos(product, id_Marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso);
		pr.leer();
		pr.modificar();
		system("cls");
		system("pause");
		pr.leer();
		system("pause");
		system("cls");
		break;
	}
	case 4: {
		Productos pr = Productos();
		pr.leer();
		pr.eliminar();
		system("pause");
		system("cls");
		break;
	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;
	}
	}
}

//proveedores
void menu_proveedores() {
	int opcion;
	cout << "-------------- Menu Productos: ----------------" << endl;
	cout << " 1. crear....." << endl;
	cout << " 2. leer....." << endl;
	cout << " 3. modificar..." << endl;
	cout << " 4. eliminar..." << endl;
	cout << " 0. Menu Principal" << endl;
	cout << " Seleccione su opcion: ";


	cin >> opcion;
	system("cls");
	switch (opcion) {

	case 1: {
		cout << " para ingresar......." << endl;

		string proveedor, nit, direccion, telefono;
		cin.ignore();
		cout << " ingrese proveedor: " << endl;
		getline(cin, proveedor);
		cout << " ingrese NIT: " << endl;
		getline(cin, nit);
		cout << " ingrese direccion: " << endl;
		getline(cin, direccion);
		cout << " ingrese telefono:" << endl;
		getline(cin, telefono);


		proveedores pr = proveedores (proveedor, nit, direccion, telefono);

		pr.crear();
		system("pause");
		system("cls");
		break;


	}
	case 2: {
		proveedores pr = proveedores();
		pr.leer();
		system("pause");
		system("cls");
		break;
	}
	case 3: {
		cout << " para modificar......." << endl;

		string proveedor, nit, direccion, telefono;
		cin.ignore();
		cout << " ingrese proveedor: " << endl;
		getline(cin, proveedor);
		cout << " ingrese NIT: " << endl;
		getline(cin, nit);
		cout << " ingrese direccion: " << endl;
		getline(cin, direccion);
		cout << " ingrese telefono:" << endl;
		getline(cin, telefono);


		proveedores pr = proveedores(proveedor, nit, direccion, telefono);

		pr.modificar();
		system("pause");
		system("cls");
		break;


	}
	case 4: {
		proveedores pr = proveedores();
		pr.eliminar();
		system("pause");
		system("cls");
		break;


	}
	case 0: {
		menu_principal();
		system("pause>nul");
		break;

	}
	}
}

	void menu_compras() {
		system("cls");
		int opcion;
		cout << "-------------- Menu Empleados: ----------------" << endl;
		cout << " 1. Crear....." << endl;
		cout << " 2. Leer....." << endl;
		cout << " 3. Modificar..." << endl;
		cout << " 4. Eliminar..." << endl;
		cout << " 0. Menu Principal..." << endl;
		cout << " Seleccione su opcion: " << endl;
		cin >> opcion;
		system("cls");
		switch (opcion) {

		case 1: {


			cout << " para insertar......." << endl;

			system("pause");
			system("cls");
			break;
		}
		case 2: {
			Compras a;
			a.leer_compras();
			system("pause");
			system("cls");
			break;

		}
		case 3: {
			cout << " para modificar......." << endl;
			
			break;
		}
		case 4: {
			Compras b;
			b.eliminar();
			system("pause");
			system("cls");
			break;
		}
		case 0: {
			menu_principal();
			system("pause>nul");
			break;
		}
		}
	}
	void menu_compras() {
		int id_proveedor, idcompra, cero, idproducto, Cantidad;
		string  fecha1 = "now()", fechaIngreso = "now()";

		char op;

		cout << ("Ingrese Id proveedor: ") << endl;
		cin >> id_proveedor;

		Compras cc = Compras(id_proveedor, fecha1, fechaIngreso);
		cc.crear(id_proveedor);

		//Comienza el detalle
		do
		{
			cout << endl << endl;
			cout << ("Ingrese Id Producto: ") << endl;

			cin >> idproducto;


			cout << ("Ingrese Cantidad: ") << endl;
			cin >> Cantidad;

			Compras2 f = Compras2(idproducto, Cantidad);
			f.Maestro_compras();

			cout << ("Te gustaria agregar un nuevo registro s-n") << endl << endl;
			cin >> op;

		} while ((op == 's') || (op == 'S'));


	}

