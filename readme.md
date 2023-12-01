# Proyecto-Estructuras-Datos

# Proyecto: Gestionador de Rocas Minerales
El proyecto Gestionador de Rocas Minerales Permite al usuario consultar y gestionar su lista de rocas y minerales. El programa contiene un archivo con todos los tipos de minerales, asi como su nombre, dureza, y valor, tras consultar esta, el usuario es capaz de registrar sus piedras y minerales y agregarlas a una lista, la cual puede ser exportada en archivo .csv 

## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp BST.h minerales.h roca_base.h roca.h leerCSV.h -o entrega_final` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

./a.out 

## Descripción de las entradas del avance de proyecto
El programa toma como entrada un archivo .csv, en el cual se lee la lista de rocas.
Se debe de seguir el formato csv:
Nombre,Dureza,Valor
Opalo,5.5,Variable
Diamante,10,Muy Alto
Lapislazuli,6,Moderado
Grafito,1.5,Bajo
Jade,7,Alto
Granate,6.5,Moderado
Obsidiana,5.5,Variable
Zafiro,9,Alto
Bismuto,2.2,Moderado
Esmeralda,8,Alto
Hematita,6,Bajo
Rubi,9,Alto
Fuera de esto, el usuario solamente ingresara datos int para seleccionar opciones del menu.

## Descripción de las salidas del avance de proyecto
Las salidas del programa se centran en mensajes dirigidos al usuario para proporcionar una experiencia informativa y fácil de entender. Al iniciar el programa, se presenta un mensaje de bienvenida junto con una descripción general de sus funcionalidades. El menú principal ofrece diversas opciones. 

Además, el programa emite mensajes específicos para informar sobre el resultado de las operaciones realizadas. Por ejemplo, se notifica al usuario si la carga de un archivo CSV fue exitosa o si se encontraron errores durante este proceso. 

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
En este proyecto, se habia utilizado el algoritmo de ordenamiento Merge Sort para ordenar la lista de rocas almacenadas en la estructura de datos del árbol de búsqueda binaria. El análisis de complejidad se centra en evaluar los peores y mejores casos de este algoritmo.

Mejor Caso:
El mejor caso para Merge Sort es cuando la lista ya está ordenada. En este escenario, el algoritmo realiza comparaciones y fusiones eficientes, ya que las divisiones y combinaciones se llevan a cabo de manera equilibrada. La complejidad de tiempo en el mejor caso es 

O(nlogn), donde 
n es el número de elementos en la lista.

Peor Caso:
El peor caso ocurre cuando la lista está completamente desordenada. A pesar de esto, Merge Sort garantiza un rendimiento consistente, ya que siempre divide la lista por la mitad y fusiona las sub-listas ordenadas. En el peor caso, la complejidad de tiempo es también 

O(nlogn).

Desaforunadamente, por falta de tiempo y claridad de ideas, la funcion mergeSort tuvo que ser comentada y omitida del programa final, ya que en un principio ordenaba los elementos del arbol, pero tras la implementación de importación de datos del csv, la función ya no era optima, aun asi el codigo esta ahi como evidencia.


#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

En el desarrollo del proyecto, tuve que llevar a cabo un análisis exhaustivo de la complejidad de las estructuras de datos utilizadas y sus respectivos usos en el programa. Al no entender muy bien, vi decenas de tutoriales en youtube, para finalmente poder implementarlo.. Para el Árbol de Búsqueda Binario (BST), se ha considerado la complejidad temporal de las operaciones clave, como la inserción, búsqueda y eliminación. En el peor caso, estas operaciones tienen una complejidad de O(h), donde "h" representa la altura del árbol. 

Métodos y Funcionalidades del Árbol
add(T val): Agrega un nuevo nodo al árbol con el valor proporcionado. Esta operación tiene una complejidad en el peor caso de O(h), donde "h" es la altura del árbol.

find(T val): Busca un valor en el árbol. La complejidad de esta operación en el peor caso es O(h), donde "h" es la altura del árbol.

preOrder(): Realiza un recorrido en preorden del árbol, generando una cadena que representa los nodos visitados. La complejidad de esta operación es O(n), donde "n" es el número de nodos en el árbol.

inOrder(): Realiza un recorrido en orden del árbol, generando una cadena que representa los nodos visitados. La complejidad de esta operación es O(n).

postOrder(): Realiza un recorrido en postorden del árbol, generando una cadena que representa los nodos visitados. La complejidad de esta operación es O(n).

lvlByLvl(): Realiza un recorrido por niveles del árbol, generando una cadena que representa los nodos visitados. La complejidad de esta operación es O(n).

height(): Devuelve la altura del árbol. La complejidad de esta operación es O(n).


nota: (El BST proporciona una forma eficiente de organizar y buscar datos, y su complejidad está vinculada a la altura del árbol, que a su vez depende del orden de inserción de los elementos.)


En el análisis de complejidad del programa actualizado, se han considerado todos los componentes para determinar la complejidad final. La operación principal sigue siendo la importación de datos desde un archivo CSV, donde cada línea se procesa para crear y agregar un nuevo objeto Roca al Árbol de Búsqueda Binario (BST). La complejidad de esta operación sigue estando dominada por la altura del árbol, que en el peor caso podría ser lineal (O(n)), especialmente si los datos están ordenados de manera que generen un árbol degenerado. No obstante, al utilizar un BST, la operación de importación generalmente tiene una complejidad promedio de O(log n).

La operación de visualización de todas las rocas ordenadas también depende de la altura del árbol y tiene una complejidad asociada de O(n) en el peor caso.

Se implemento la capacidad de escribir un archivo CSV con los datos actuales del árbol. Esta operación implica recorrer todos los nodos del árbol para obtener la información necesaria, lo que contribuye a la complejidad general.

En resumen, al considerar todas las operaciones del programa, la complejidad final sigue siendo principalmente determinada por la operación de importación y la operación de ordenamiento, ambas con una complejidad promedio de O(n log n). Las operaciones adicionales, como la eliminación, la visualización y la escritura de archivos CSV, también están influenciadas por la altura del árbol y se mantienen dentro de límites aceptables para conjuntos de datos moderados.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

En el proyecto, se habia pensado implementar el algoritmo de ordenamiento Merge Sort para ordenar la lista de rocas almacenadas en un árbol de búsqueda binario.
El Merge Sort tiene una complejidad temporal de O(n log n), donde "n" es el número de elementos en la lista a ordenar. Este análisis se basa en la división recursiva de la lista en mitades y la combinación ordenada de esas mitades. Aunque el Merge Sort tiene una complejidad teórica mayor que algunos otros algoritmos de ordenamiento, como el Quick Sort, su rendimiento constante y su eficiencia en escenarios de datos vinculados lo convierten en una elección sólida para este programa.

La implementación del Merge Sort no se llevó a cabo finalmente.

Desde el inicio del proyecto, he seleccionado y utilizado de manera eficiente una estructura de datos clave: el Árbol de Búsqueda Binaria (BST), para gestionar la información relacionada con las rocas y minerales en el programa. Esta elección se fundamenta en la necesidad de organizar y buscar de manera eficaz la información basada en el nombre de las rocas.

La estructura del Árbol de Búsqueda Binaria posibilita una búsqueda eficiente, con una complejidad promedio de O(log n) para operaciones como la búsqueda, inserción y eliminación de elementos, donde "n" es el número de elementos en el árbol. Además, he implementado una función para vaciar completamente el árbol, lo cual resulta crucial en situaciones en las que es necesario reorganizar o limpiar la lista de rocas.

La aplicación de esta estructura de datos se refleja en diversas partes del código, desde la inserción de nuevas rocas hasta la búsqueda y eliminación de rocas existentes. En general, la elección y la implementación de la estructura de datos han contribuido a un rendimiento eficiente del programa en términos de búsqueda y manipulación de datos.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.

En el desarrollo de este proyecto, he implementado mecanismos efectivos para consultar información de las estructuras utilizadas. El principal componente para la gestión de información es el Árbol de Búsqueda Binaria (BST), implementado en la clase BST. Este árbol permite realizar búsquedas eficientes, inserciones y eliminaciones con una complejidad promedio de O(log n), lo cual se traduce en un acceso rápido y eficiente a los datos almacenados.

La implementación de la búsqueda de elementos en el árbol (find en TreeNode) se realiza de manera recursiva, proporcionando una solución efectiva para la recuperación de datos basada en el valor de búsqueda.

Adicionalmente, la estructura de datos Minerales utiliza el árbol BST para gestionar las rocas y minerales, lo que facilita la consulta de información relacionada con estos elementos. La función displayRocas permite visualizar la lista de rocas almacenadas, proporcionando una forma clara y organizada de revisar la información.

En términos de eficiencia, la implementación de estructuras como el árbol BST y la aplicación de algoritmos de ordenamiento como el merge sort contribuyen a mantener un rendimiento óptimo del programa, especialmente en operaciones que implican la manipulación y búsqueda de datos.

La implementación de la lectura de archivos CSV en la clase LeerCSV también es clave para el manejo de datos. Esta clase proporciona un mecanismo robusto para extraer información estructurada desde archivos CSV, lo que facilita la importación de datos externos al programa.

En resumen, he logrado implementar mecanismos científicos sólidos para consultar información de las estructuras, aprovechando eficientemente las características de las mismas y facilitando la interacción con datos externos mediante la lectura de archivos CSV. 

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Desde el principio del proyecto se me dificulto mucho esta sección, iba a realizarlo en .txt, pero finalmente opte por csv, y he implementado estos mecanismos de lectura de archivos para cargar datos en las estructuras de manera precisa y efectiva, aunque sacrificando otras partes del proyecto. 

Implemente de manera efectiva mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta. La clase LeerCSV desempeña un papel fundamental en este proceso, proporcionando una solución robusta y eficiente para la lectura de datos desde archivos CSV.

La función leerCSV de la clase LeerCSV utiliza flujos de entrada para abrir y leer archivos CSV. Durante la lectura, se procesa cada línea del archivo, dividiéndola en elementos utilizando un separador especificado (por defecto, la coma). Los datos se almacenan en una estructura de vectores bidimensionales que representa las filas y columnas del archivo CSV.

Este mecanismo de lectura de archivos se aplica de manera adecuada en la carga de datos al programa, permitiendo la importación de información externa de manera estructurada y eficiente. La función leerCSV devuelve un vector bidimensional que contiene los datos del archivo, facilitando su posterior procesamiento y almacenamiento en las estructuras correspondientes.

La implementación de este mecanismo ha demostrado ser efectiva y versátil, adaptándose a diferentes archivos CSV con variados tamaños y estructuras de datos. Además, se han considerado casos de manejo de errores, como la detección de la apertura fallida de un archivo.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
Se interactúa con el usuario solicitándole que ingrese el nombre del nuevo archivo CSV que se creará, permitiendo una personalización significativa.

Posteriormente, el programa solicita al usuario el nombre del archivo CSV existente del cual se copiará la información. Utiliza la clase LeerCSV para leer los datos de este archivo y los almacena en la variable existingData. Se procede a crear un nuevo vector de datos llamado data, utilizando la información recopilada del archivo CSV existente. Cada fila en este nuevo vector contiene los mismos datos que la fila correspondiente en existingData, asegurando la consistencia de la información.

Finalmente, se utiliza la clase gestionadorMinerales para escribir el nuevo archivo CSV, especificado por el usuario, con los datos recopilados en el vector data. Este proceso garantiza que la información se almacene correctamente en el nuevo archivo. Como confirmación de la finalización exitosa del procedimiento, se imprime un mensaje indicando que el archivo CSV se ha creado con éxito. 

### Evidencia 2 - Problemas
Links:<br> 
1: https://youtu.be/UAg5Q_zuj8I<p> 
2: https://youtu.be/kwtp48eu3XY<p> 
3: https://youtu.be/5y9jhA-JL1I<p> 
