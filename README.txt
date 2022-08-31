Para el TP4 de la materia testing de software se realiza el testing sobre la lectura de un sensor de temperatura lineal, LM35, conectado por ADC a la placa LPC1768. 
Tambien se agrega una funcion para realizar el promedio de mediciones de diferentes temperaturas. 
La funcion para leer temperatura tiene en cuenta solo el rango de temperatura positivo del sensor. 
Para utlizar el rango negativo de temperaturas del sensor es necesario conectar el mismo de otra forma. Por ejemplo con diodos entre tierra y la pata de gnd para correr la referencia. 
En ese caso es necesario medir la tension en dos puntos, y hacer la resta para luego calcular la temperatura.

NOTA: El testing se basa en una implementacion real de un trabajo realizado hace muchos años atras para una empresa privada, al no contar con el software original, se realizaron busquedas de codigos similares y se adaptaron para realizar el testing. 
En el software original se realizaban mediciones de temperaturas en diferentes partes del dispositivo (con mas de un sensor de temperatura) y luego se realizaba un promedio para obtener la temperatura del dispositivo.
