#ifndef VARIABLES_H
#define VARIABLES_H

#include "constantes.h"
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

/**
   Clase que almacena las variables definidas por el usuario.
*/
class VariablesTest {

	private:

		/* Estructura interna de una variable

			nombre, la expresión, el valor numérico de la expresión,
			la descripción para la variable, y un booleano para saber si
			es una constante o variable.

		*/
        struct Variable {
            char var_name[MAX_TOKEN_ID];
            char expression[MAX_TOKEN_ID];
			double value;
            char description[MAX_TOKEN_ID];
            bool is_constant;
        };

		/*
			Estructura necesaria para poder ordenar las variables basandose en su
			nombre.
		*/
        struct sort_key_var {
            inline bool operator() (const Variable& struct1, const Variable& struct2) {
                return (std::string(struct1.var_name).compare(struct2.var_name) < 0);
			}
		};

		// La lista de variables definidas por el usuario:
		mutable std::vector<Variable> var_list;

	public:

		/*
        	Método para ordenar la lista.
		*/
		inline void sort(void) {
			std::sort(var_list.begin(), var_list.end(), sort_key_var());
		}

		/*
        	Regrese la lista de variables.
		*/
        inline std::vector<Variable>& get_vars(void) const {
            return var_list;
		}

		/* Sobrecarga del operador [] para poder acceder a la lista de variables
			de manera más cómoda.

			Ejemplo:
			variables[0].get_name()

			*/
        inline Variable& operator[](size_t index) {
            return var_list[index];
        }

        /**
          Sobrecarga del operador << para poder mostrar en la salida estandar
          las variables definidas por el usuario.
          */
        friend std::ostream& operator<<(std::ostream& out, const VariablesTest& varsList) {
            out << std::endl;
            for(unsigned int i = 0; i < varsList.var_list.size(); i++) {
                out
				<< "Var{"
				<< varsList.var_list[i].var_name
				<< "}, {"
				<< varsList.var_list[i].expression
				<< "}, Val{"
				<< varsList.var_list[i].value
				<< "}, constant{"
				<< std::boolalpha << varsList.var_list[i].is_constant
				<< "}, Desc{"
                << varsList.var_list[i].description
                << "}"
                << std::endl;
            }
            return out;
        }

        /** Getters de la clase */
		/*
        	Regresa el valor numérico de la variable con nombre "name"
		*/
        inline double get_value(const char* name) {
            int index = get_index(name);
            return var_list[index].value;
        }

		// Saber si es constante o no
		/*
			Regresa un true si la "name" es variable o false si es constante
		*/
        inline bool is_constant(const char* name) {
			int index = get_index(name);
			if(index != -1) {
				return var_list[index].is_constant;
			} else {
            	return false;
			}

        }

		/*
        	Regresa la expresión de la variable "name"
		*/
        inline char* get_expression(const char* name) const {
            int index = get_index(name);
            return var_list[index].expression;      /** Ejemplo */
        }

        // Obtener la descripción de la variable
        inline char* get_description(const char* name) const {
            int index = get_index(name);
            return var_list[index].description;      /** Ejemplo */
        }

        /// Setters:
		/*
        	Cambiar el nombre de una variable (old_name) por (new_name).
		*/
        inline bool change_name(const char* old_name, const char* new_name) {
            if(exists(old_name)) {
                int index = get_index(old_name);
                strcpy(var_list[index].var_name, new_name);
                return true;
            }
            return false;
        }

		/* Cambia el valor numérico de una variable (name)
		*/
        inline bool change_value(const char* name, double value) {
            if(exists(name)) {
                int index = get_index(name);
                var_list[index].value = value;
                return true;
            }
            return false;
        }

		/*
          	Cambiar la expresión de una variable (name).
		*/
        inline bool change_expression(const char* name, const char* new_expression) {
            if(exists(name)) {
                int index = get_index(name);
                strcpy(var_list[index].expression, new_expression);
                return true;
            }
            return false;
        }

		/*
			Cambia la descripción de una variable.
			Parámetros:
			name: El nombre de la variable a la cual cambiar la descripción.
			new_description: La descripción para la variable.
		*/
        inline bool change_description(const char* name, const char* new_description) {
            if(exists(name)) {
                int index = get_index(name);
                strcpy(var_list[index].description, new_description);
                return true;
            }
            return false;
        }

		/*
			Cambia la variable constant de la variable, haciendola constante
			o variable según sea el caso.
			Parámetros:
			name: El nombre de la variable a modificar.
			const_var:	El valor a asignar en el campo is_constant de la variable.
		*/
        inline bool change_constant_value(const char* name, bool const_var) {
            if(exists(name)) {
                int index = get_index(name);
				var_list[index].is_constant = const_var;
                return true;
            }
            return false;
        }


		/*
			Elimina una variable de la lista.
			Parámetros:
			name: El nombre de la variable a eliminar.
		*/
		inline bool del(const char* name) {

            if(exists(name)) {
                var_list.erase(var_list.begin() + get_index(name));
                return true;
			}

            return false;
        }

		/*
			Comprueba si una variable existe en la lista.
			Parámetros:
			name: El nombre a comprobar si existe en la lista.
		*/
        inline bool exists(const char* name) const {
			for(size_t i = 0; i < var_list.size(); i++) {
				if(strcmp(name, var_list[i].var_name) == 0) {
					return true;
				}
			}
            return false;
		}

		/*inline bool exists_var(const char* name) const {
			for(size_t i = 0; i < var_list.size(); i++) {
				if((strcmp(name, var_list[i].var_name) == 0) && !var_list[i].is_constant) {
					return true;
				}
			}
			return false;
		}*/

		/*
			Agrega una nueva variable a la lista.
			Parámetros:
			name: El nombre de la nueva variable a agregar.
			value: El valor numérico a asignar en la nueva variable.

			Si la variable ya existe solo se modifica la existente.

		*/
        inline bool add(const char* name, double value) {

            // Crear la variable e inicializarla:
            Variable new_var;

            strncpy(new_var.var_name, name, MAX_TOKEN_ID);
            strcpy(new_var.description, "");
            strcpy(new_var.expression, "");
            new_var.is_constant = false;
            new_var.value = value;

            // La variable no existe, crearla.
            if(exists(name) == false) {
                var_list.push_back(new_var);
            } else {    // La variable sí existe, crearla
                int index = get_index(name);
                var_list[index] = new_var;
            }
            return true;
        }

		// Devolver el índice
		/*
			Devuelve la posición de una variable en la lista.
			Parámetros:
			name: El nombre de la variable a devolver su posición.

			Si la variable no existe en la lista se regresa un -1.
		*/
        inline int get_index(const char* name) const {
            for(size_t i = 0; i < var_list.size(); i++) {
                if(strcmp(name, var_list[i].var_name) == 0) {
                    return i;
                }
            }
            return -1;
        }

		/*
			Agrega una nueva variable a la lista.
			Parámetros:
			name: El nombre de la nueva variable a agregar.
			expression: La expression a asignar a la nueva variable.
			value: El valor numérico a asignar en la nueva variable.

			Si la variable ya existe solo se modifica la existente.

		*/
        inline bool add(const char* name, const char* expression, double value) {
			// Crear la variable e inicializarla:
			Variable new_var;

			strncpy(new_var.var_name, name, MAX_TOKEN_ID);
			strcpy(new_var.description, "");
			strcpy(new_var.expression, expression);
			new_var.is_constant = false;
			new_var.value = value;

			// La variable no existe, crearla.
			if(exists(name) == false) {
				var_list.push_back(new_var);
			} else {    // La variable sí existe, crearla
				int index = get_index(name);
				var_list[index] = new_var;
			}

			return true;
		}

        /*
			Agrega una nueva variable a la lista.
			Parámetros:
			name: El nombre de la nueva variable a agregar.
			expression: La expression a asignar a la nueva variable.
			value: El valor numérico a asignar en la nueva variable.
			is_constant: El valor booleano a asignar a la varable, true si
			será constante, false si será una variable.

			Si la variable ya existe solo se modifica la existente.

		*/
		inline bool add(const char* name, const char* expression, double value, bool is_constant) {
			// Crear la variable e inicializarla:
			Variable new_var;

			strncpy(new_var.var_name, name, MAX_TOKEN_ID);
			strcpy(new_var.description, "");
			strcpy(new_var.expression, expression);
			new_var.is_constant = is_constant;
			new_var.value = value;

			// La variable no existe, crearla.
			if(exists(name) == false) {
				var_list.push_back(new_var);
			} else {    // La variable sí existe, crearla
				int index = get_index(name);
				var_list[index] = new_var;
			}

			return true;
		}

		/*
			Agrega una nueva variable a la lista.
			Parámetros:
			name: El nombre de la nueva variable a agregar.
			expression: La expression a asignar a la nueva variable.

			Si la variable ya existe solo se modifica la existente.

		*/
		inline bool add(const char* name, const char* expression) {

			Variable new_var;

			strncpy(new_var.var_name, name, MAX_TOKEN_ID);
			strcpy(new_var.description, "");
			strcpy(new_var.expression, expression);
			new_var.is_constant = false;
			new_var.value = 0.0;

			if(exists(name) == false) {
				var_list.push_back(new_var);
			} else {
				int index = get_index(name);
				var_list[index] = new_var;
			}
			return true;
		}

		/*
        	Vacíar la lista de variables.
		*/
		inline void clear_vars(void) const {
            var_list.clear();
        }

		/*
        	Regresa el tamaño de la lista.
		*/
        inline int var_count(void) const {
            return var_list.size();
        }

        /*
        	Regresa el tamaño de la lista.
		*/
        inline size_t size(void) const {
            return var_list.size();
        }

		/* Regresa la cantidad de variables en la lista.
		 */
		inline unsigned vars_count(void) const {
			unsigned count = 0;
			for(size_t i = 0; i < var_list.size(); i++) {
				if(!var_list[i].is_constant) {
					count++;
				}
			}
            return count;
        }

		/*
        	Regresa la cantidad de constantes en la lista.
		*/
		inline unsigned constants_count(void) const {
            unsigned count = 0;
            for(size_t i = 0; i < var_list.size(); i++) {
                if(var_list[i].is_constant) {
                    count++;
                }
            }
            return count;
		}

		/*
			Regresa una lista temporal de las variables en la lista.
		*/
		inline std::vector<Variable> get_vars() {
			std::vector<Variable> v;
			for(size_t i = 0; i < var_list.size(); i++) {
				if(var_list[i].is_constant == false) {
					v.push_back(var_list[i]);
				}
			}
			return v;
		}

		/*
			Regresa una lista temporal de las constantes en la lista.
		*/
		inline std::vector<Variable> get_constants() {
			std::vector<Variable> v;
			for(size_t i = 0; i < var_list.size(); i++) {
				if(var_list[i].is_constant == true) {
					v.push_back(var_list[i]);
				}
			}
			return v;
		}

};

#endif

