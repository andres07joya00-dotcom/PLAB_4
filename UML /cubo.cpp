/**
 * @file main.cpp
 * @brief Implementación de la clase Cube y demostración de su uso.
 * 
 * Este programa define una clase `Cube` que representa un cubo en el espacio,
 * con métodos para calcular su volumen y su área superficial. En el `main`
 * se crean instancias de la clase y se muestran los resultados en consola.
 * 
 * @author Faro
 * @date 2025-10-30
 */

 #include <iostream>
 using namespace std;
 
 /**
  * @class Cube
  * @brief Representa un cubo con una longitud de arista determinada.
  * 
  * La clase incluye métodos para obtener y modificar la longitud del cubo,
  * así como para calcular su volumen y área superficial.
  * 
  * @note Se puede ampliar fácilmente para representar prismas rectangulares.
  * @warning No acepta longitudes negativas ni nulas.
  * @see getVolume(), getSurfaceArea(), setLength()
  */
 class Cube {
 protected:
     // (No hay atributos protegidos en esta versión)
 
 private:
     double length; ///< Longitud de la arista del cubo.
 
 public:
     /**
      * @brief Constructor con parámetro.
      * @param l Longitud inicial de la arista (por defecto 1.0).
      */
     Cube(double l = 1.0) : length(l) {}
 
     /**
      * @brief Constructor por defecto.
      * 
      * Inicializa el cubo con una longitud de 1.0.
      */
     Cube() {
         length = 1.0;
     }
 
     /**
      * @brief Obtiene la longitud actual de la arista del cubo.
      * @return Longitud de la arista.
      */
     double getLength() const {
         return length;
     }
 
     /**
      * @brief Establece una nueva longitud para la arista del cubo.
      * 
      * Solo se aceptan valores positivos.
      * 
      * @param l Nueva longitud de la arista.
      * @see getLength()
      */
     void setLength(double l) {
         if (l > 0) // Se asegura de que la longitud sea válida
             length = l;
     }
 
     /**
      * @brief Calcula el volumen del cubo.
      * 
      * Fórmula: \f$ V = l^3 \f$
      * 
      * @return Volumen del cubo.
      */
     double getVolume() const {
         return length * length * length;
     }
 
     /**
      * @brief Calcula el área superficial del cubo.
      * 
      * Fórmula: \f$ A = 6 \times l^2 \f$
      * 
      * @return Área superficial del cubo.
      */
     double getSurfaceArea() const {
         return 6 * length * length;
     }
 };
 
 /**
  * @brief Función principal del programa.
  * 
  * Crea objetos `Cube`, muestra sus propiedades y modifica sus longitudes.
  * 
  * @param argc Número de argumentos.
  * @param argv Vector con los argumentos.
  * @return 0 si el programa finaliza correctamente.
  */
 int main(int argc, char ** argv) {
     
     Cube c(3.0); ///< Crea un cubo con longitud 3.
     Cube c2(1);     ///< Crea un cubo con longitud por defecto (1).
 
     cout << "Length: " << c.getLength() << endl;
     cout << "Volume: " << c.getVolume() << endl;
     cout << "Surface Area: " << c.getSurfaceArea() << endl;
 
     // Modificar la longitud
     c.setLength(5.0);
     cout << "\nAfter setting length to 5:\n";
     cout << "Length: " << c.getLength() << endl;
     cout << "Volume: " << c.getVolume() << endl;
     cout << "Surface Area: " << c.getSurfaceArea() << endl;
 
     return 0;
 }
 
 