# Proyecto-Estructuras-Datos

# Proyecto: Gestionador de Rocas Minerales
El proyecto Gestionador de Rocas Minerales Permite al usuario consultar y gestionar su lista de rocas y minerales. El programa contiene un archivo con todos los tipos de minerales, asi como su nombre, dureza, y valor, tras consultar esta, el usuario es capaz de registrar sus piedras y minerales y agregarlas a una lista, borrar la lista, ordenar las piedras y minerales a traves de un merge y finalmente siendo capaz de lectura y escritura de archivos csv

## Instrucciones para compilar el proyecto
Ejecuta el siguiente comando en la terminal:

`g++ main.cpp BST.h mergeSort.h minerales.h roca_base.h roca.h -o entrega_final` 

## Instrucciones para ejecutar el proyecto
Ejecuta el siguiente comando en la terminal:

`./a.out 

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
Las salidas del programa se centran en mensajes dirigidos al usuario para proporcionar una experiencia informativa y fácil de entender. Al iniciar el programa, se presenta un mensaje de bienvenida junto con una descripción general de sus funcionalidades. El menú principal ofrece diversas opciones, cada una acompañada de mensajes explicativos que guían al usuario en la selección de la acción deseada.

Además, el programa emite mensajes específicos para informar sobre el resultado de las operaciones realizadas. Por ejemplo, se notifica al usuario si la carga de un archivo CSV fue exitosa o si se encontraron errores durante este proceso. Estos mensajes de error están diseñados para ser claros y descriptivos, brindando al usuario la información necesaria para comprender y abordar cualquier problema.

## Desarrollo de competencias

### SICT0301: Evalúa los componentes
En este proyecto, se ha utilizado el algoritmo de ordenamiento Merge Sort para ordenar la lista de rocas almacenadas en la estructura de datos del árbol de búsqueda binaria. El análisis de complejidad se centra en evaluar los peores y mejores casos de este algoritmo.

Mejor Caso:
El mejor caso para Merge Sort es cuando la lista ya está ordenada. En este escenario, el algoritmo realiza comparaciones y fusiones eficientes, ya que las divisiones y combinaciones se llevan a cabo de manera equilibrada. La complejidad de tiempo en el mejor caso es 

O(nlogn), donde 
n es el número de elementos en la lista.

Peor Caso:
El peor caso ocurre cuando la lista está completamente desordenada. A pesar de esto, Merge Sort garantiza un rendimiento consistente, ya que siempre divide la lista por la mitad y fusiona las sub-listas ordenadas. En el peor caso, la complejidad de tiempo es también 

O(nlogn).

Aprendizaje:
El análisis de complejidad para Merge Sort en este proyecto destaca la eficacia de este algoritmo, ya que ofrece un rendimiento estable independientemente del estado de orden de la lista. Además, la implementación de Merge Sort se integra de manera efectiva en el flujo del programa, mejorando la eficiencia de operaciones como la visualización y el procesamiento de las rocas.

Observación del Desarrollo:
El desarrollo de la competencia se evidencia en la selección y aplicación adecuada de un algoritmo de ordenamiento. La elección de Merge Sort se basa en su eficiencia y estabilidad en diferentes casos, lo que mejora el rendimiento general del programa en términos de operaciones de ordenamiento sobre la información de rocas almacenada

#### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.
En el desarrollo del proyecto, tuve que llevar a cabo un análisis exhaustivo de la complejidad de las estructuras de datos utilizadas y sus respectivos usos en el programa. Al no entender muy bien, vi decenas de tutoriales en youtube, para finalmente poder implementarlo.. Para el Árbol de Búsqueda Binario (BST), se ha considerado la complejidad temporal de las operaciones clave, como la inserción, búsqueda y eliminación. En el peor caso, estas operaciones tienen una complejidad de O(h), donde "h" representa la altura del árbol. Aunque la altura puede afectar el rendimiento, se ha tenido en cuenta la implementación de funciones de balanceo para abordar este aspecto.

Asimismo, se ha evaluado la complejidad de las operaciones en un vector (std::vector), utilizado para almacenar temporalmente las rocas durante el proceso de ordenamiento. Las operaciones de inserción y acceso aleatorio en un vector tienen una complejidad de O(1), mientras que la eliminación en el peor caso es O(n), ya que puede implicar el desplazamiento de elementos.



#### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

En el análisis de complejidad del programa, se ha considerado cada uno de sus componentes para determinar la complejidad final. La operación principal es la importación de datos desde un archivo CSV, donde cada línea se procesa para crear y agregar un nuevo objeto Roca al Árbol de Búsqueda Binario (BST). La complejidad de esta operación está dominada por la altura del árbol, que en el peor caso podría ser lineal (O(n)), especialmente si los datos están ordenados de manera que generen un árbol degenerado. Sin embargo, dado que el programa utiliza un BST, la operación de importación generalmente tiene una complejidad promedio de O(log n).

La operación de ordenamiento utilizando el algoritmo Merge Sort se aplica a la lista de rocas almacenadas en el BST. El proceso de ordenamiento tiene una complejidad de O(n log n), donde "n" es el número de rocas en la lista. Este paso garantiza que las rocas estén ordenadas de manera eficiente según ciertos criterios, mejorando la eficacia de futuras operaciones de búsqueda y visualización.

En cuanto a la operación de eliminación de una roca del BST, su complejidad está asociada con la altura del árbol y puede variar desde O(log n) hasta O(n) en el peor caso, según la estructura del árbol. Sin embargo, se ha implementado una función para eliminar recursivamente los nodos y ajustar la estructura del árbol, mitigando posibles problemas de rendimiento.

La operación de visualización de todas las rocas ordenadas también depende de la altura del árbol y, por ende, tiene una complejidad asociada de O(n) en el peor caso.

En resumen, al considerar todas las operaciones del programa, la complejidad final es principalmente determinada por la operación de importación y la operación de ordenamiento, ambas con una complejidad promedio de O(n log n). La complejidad de las operaciones adicionales, como la eliminación y la visualización, está influida por la altura del árbol y se mantiene dentro de límites aceptables para conjuntos de datos moderados.

### SICT0302: Toma decisiones
#### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En el proyecto, se implementó el algoritmo de ordenamiento Merge Sort para ordenar la lista de rocas almacenadas en un árbol de búsqueda binario.
El Merge Sort tiene una complejidad temporal de O(n log n), donde "n" es el número de elementos en la lista a ordenar. Este análisis se basa en la división recursiva de la lista en mitades y la combinación ordenada de esas mitades. Aunque el Merge Sort tiene una complejidad teórica mayor que algunos otros algoritmos de ordenamiento, como el Quick Sort, su rendimiento constante y su eficiencia en escenarios de datos vinculados lo convierten en una elección sólida para este programa.
La implementación del Merge Sort se llevó a cabo correctamente en la función mergeSortRoca dentro de la clase Minerales. La función utiliza una estructura de datos de árbol de búsqueda binario (BST) para almacenar y gestionar las rocas. Se obtiene una lista ordenada de las rocas mediante un recorrido inorden del árbol, y luego se aplica el algoritmo Merge Sort para ordenar eficientemente la lista.

#### Selecciona una estructura de datos adecuada al problema y la usa correctamente.
Desde el inicio del proyecto, he utilizado una estructura de datos clave, el árbol binario de búsqueda (BST, por sus siglas en inglés), para gestionar la información relacionada con las rocas y minerales en el programa. Esta elección se basa en la necesidad de organizar y buscar eficientemente la información en función del nombre de las rocas.

La estructura del árbol binario de búsqueda permite una búsqueda eficiente, con una complejidad de O(logn) en promedio para la búsqueda, inserción y eliminación de elementos, donde n es el número de elementos en el árbol. Además, he implementado una función para vaciar completamente el árbol, lo cual es crucial para situaciones en las que se necesita reorganizar o limpiar la lista de rocas.

El uso de esta estructura de datos se observa en diversas partes del código, desde la inserción de nuevas rocas hasta la búsqueda y eliminación de rocas existentes. Además, la función de ordenamiento Merge Sort se aplica a una lista extraída del árbol binario para presentar la información ordenada. En general, esta elección y aplicación de la estructura de datos han contribuido a un rendimiento eficiente del programa en términos de búsqueda y manipulación de datos.

### SICT0303: Implementa acciones científicas
#### Implementa mecanismos para consultar información de las estructras correctos.
La función find en la clase BST se utiliza para buscar rocas específicas en el árbol. Además, he implementado funciones como displayRocas que aprovechan la estructura del árbol para realizar recorridos ordenados e imprimir la información de las rocas de manera organizada. También he creado una función saveCSV que utiliza la información ordenada del árbol para guardarla en un archivo CSV.

Estas implementaciones demuestran la correcta consulta de información de las estructuras, ya que se utilizan métodos específicos de la estructura de datos y se aprovechan sus propiedades para realizar operaciones de manera eficiente. El uso de estas funciones se puede observar en el código relacionado con la visualización y almacenamiento de información de las rocas y minerales.

#### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
Desde el principio del proyecto se me dificulto mucho esta sección, iba a realizarlo en .txt, pero finalmente opte por csv, y he implementado estos mecanismos de lectura de archivos para cargar datos en las estructuras de manera precisa y efectiva. La función importCSV en la clase Minerales se encarga de leer un archivo CSV y agregar las rocas correspondientes al árbol binario de búsqueda (BST).

Esta función ha sido diseñada para manejar archivos CSV con un formato específico, extrayendo la información necesaria y creando objetos de roca para luego agregarlos al árbol. Se utilizan flujos de entrada, como ifstream, para abrir y leer el archivo de manera secuencial, y se realiza un procesamiento de cada línea para extraer los datos relevantes.

El desarrollo de esta funcionalidad se evidencia en el código de la función importCSV. Además, he manejado posibles casos de error, como la falta de apertura del archivo, para garantizar una carga adecuada de datos y brindar un manejo robusto de la lectura de archivos.

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta
 La función saveCSV en la clase Minerales es responsable de escribir los datos del árbol binario de búsqueda (BST) en un archivo CSV.

En esta función, se utiliza un flujo de salida (ofstream) para abrir y escribir en el archivo especificado. Se recorre el árbol en orden para obtener una lista ordenada de rocas, y luego se escribe cada roca en una nueva línea del archivo CSV. Esto garantiza que los datos se guarden de manera organizada y que el archivo resultante sea coherente.

El código de la función saveCSV refleja el manejo adecuado de la escritura de archivos y la exportación de datos desde la estructura principal del programa. Se ha prestado especial atención a la consistencia y formato del archivo de salida para asegurar que los datos puedan ser recuperados y utilizados de manera correcta en futuras ejecuciones del programa.

### Evidencia 2 - Problemas
Links:<br> 
1: https://youtu.be/UAg5Q_zuj8I<p> 
2: https://youtu.be/kwtp48eu3XY<p> 
3: https://youtu.be/5y9jhA-JL1I<p> 
