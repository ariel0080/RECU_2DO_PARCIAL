/** Guarda en archivo la info que esta en memoria
 *
 * \param ArrayList*
 * \return void
 *
 */
void guardarArchivo(ArrayList*);

/** Pide al usuario que ingrese un campo requerido
 *
 * \param char*
 * \return int
 *
 */
int consulta(char*);

/** Busca dentro del arraylist el maximo id y genera un id igual al encontrado mas uno
 *
 * \param ArrayList*
 * \return int
 *
 */
int buscarMaxId(ArrayList*);

/** Valida el campo Hora, que sea numerco y que este etre 0 y 240
 *
 * \param hora char*
 * \return int
 *
 */
int validarHora(char* hora);

/** Genera el alta manual de un elemento del array
 *
 * \param ArrayList*
 * \return int
 *
 */
int altaManual(ArrayList*);

void guardarArchivo_20(ArrayList*);
