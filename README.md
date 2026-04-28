# tl1-tp3-2026-VictoriaFagre
*2_1)Cuando uso los recursos de libreria de string es mas que nada para un "resize" uso el resize para que a partir de demasiados caracteres pueda achicar el tamaño comparando de lo que escribí del total y luego asignándolo a por memoria dinámica a lo justo y necesario a una cadena nueva que ya puede tomar por defecto por ser puntero a*

# Observación 24/04/26
*Cuando trato de pasar un valor ingresado por teclado como cadena de caracteres, debe de ser indicado como puntero, ya que tiene varias letras que ocupan un lugar en memoria, no solo uno. Por eso debe de pasarse por referencia, si i arrreglo de caracteres YA ESTA AJUSTADO al tamaño de las letras a pasar debo de definir en el parámetro de la función receptora un char *claveAux; para que tome la dirección de memoria de clave1 y pueda trabajar con sus elementos*

# Observación 25/04/26
*Al haber hecho el merge entre ambas ramas del branch se juntaron ambas funciones pero contenian el mismo nombre y ocupaban el mismo espacio. Por lo que le cambie el nombre a cada una luego de copiarlas en el result(1ero a la que es por Id y luego a la que es por nombre). Luego le dí click a "Completar Merge" en ventana de result.*

# Observación 28/04/26
*Cuando hablo de un struct anidado tengo que liberar siempre las memorias de los mallocs utilizadas desde adentro hacia afuera. Para modulizarlo mejor se hace una función que utiliza un for para ir usando un free por cada malloc, en este caso usé: free(clienAux[i].NombreCliente); free(clientes[i].Productos); y fuera de ese for hice un free de la totalidad de la estructura de datos contenedora: free(clienAux);*

*El objetivo de liberar desde adentro hacia afuera hace que no pierda las direcciones de memoria de los punteros/struct interno y hace que pierda las direcciones y ya no podés limpiar mi RAM correctamente*

# Respecto al arreglo global y a su "liberación en malloc":
*¿Por qué no liberamos "TipoProducto"?*
*Porque prod[j].TipoProducto = TiposProductos[indiceAux]; apunta a una dirección de memoria estática (la que definí arriba de todo). Como no usé malloc para ese string específico, no debo usar free ahí.*

*Siempre la regla de oro es:<hay malloc => hay que usar free>*

# Ventajas del uso de fgets 
*1. Seguridad: Si el buffer es de 50 y el usuario escribe 100 letras, fgets solo toma 49 y corta ahí, evitando que el programa explote (buffer overflow).*

*2. Espacios: A diferencia de scanf("%s", ...), fgets sí permite leer nombres completos con espacios (ej: "Juan Perez").*

*fgets(donde_guardo, cuanto_guardo, de_donde_lo_tomo);*



