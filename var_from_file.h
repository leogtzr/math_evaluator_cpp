#ifndef VARFROMFILE_H
#define VARFROMFILE_H

#include <string>

/*
	Clase que almacena la estructura de una variable.

	La estructura de una variable es:

	NombreDeLaVariable
    Lista de valores (expresiones para la variable).

*/

/*
	Ejemplo de archivo de variables:

file.var:
a;1+2;34;1+sin(pi+2)

	La línea "a;1+2;34;1+sin(pi+2)" representa la variable "a" con sus listas de
	valores "1+2", "34" y "1+sin(pi+2)"

*/

class VarFromFile {

	public:
		/*
			Constructor
			Parámetros

			variable_name: Nombre para la variable.
		*/
		VarFromFile(std::string variable_name) : var_name(variable_name) {}

		/*
        	Regresa el nombre de la variable.
		*/
        inline std::string& get_var_name(void) {
            return var_name;
        }

		/*
        	Regresa la lista de valores de la variable.
		*/
        inline std::vector<std::string>& get_list_values(void) {
            return list_values;
        }

		/*
			Sobrecarga del operador <<, con propósitos de depuración.
        	Esto nos permite mostrar el estado del objeto y ver su contenido.
		*/
		friend std::ostream& operator<<(std::ostream& out, const VarFromFile& var_file) {
			out << "'" << var_file.var_name << "' {" << std::endl;
			for(std::vector<std::string>::const_iterator it = var_file.list_values.begin();
					it != var_file.list_values.end(); ++it) {
				out << '\t' << *it << std::endl;
			}
			out << '}' << std::endl;
			return out;
        }

		/*
			Sobrecarga del operador[] con la finalidad de poder acceder a la
			variable de manera más cómoda, por ejemplo así:

            var[0]: regresaría el valor de la lista en la posición 0.

		*/
		inline std::string& operator[](unsigned int index) {
			return list_values[index];
        }

	private:
	/*
    	Las variables de instancia.
	*/
		std::string var_name;					// Nombre de la variable
        std::vector<std::string> list_values;	// Lista de valores
};

#endif
