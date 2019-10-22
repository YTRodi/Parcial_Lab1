
int menuInformesClientes();
void imprimirJuegosMesa(eJuego vecJuego[],int tJue, eCategoria vecCategoria[],int tCate);

void imprimirAlquileresPorClienteSeleccionado(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate,
                                              eLocalidad vecLocalidad[],int tLoca);

void imprimirTotalDeImportes(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli, eJuego vecJuego[],int tJue,
                             eLocalidad vecLocalidad[],int tLoca);

void imprimirClientesQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eCliente vecCliente[],int tCli,
                                     eLocalidad vecLocalidad[],int tLoca);

void imprimirJuegosQueNoAlquilaron(eAlquiler vecAlquiler[],int tAlqui,eJuego vecJuego[],int tJue,eCategoria vecCategoria[],int tCate);


int tienePedidoAlquiler(int idAIgualar,eAlquiler vecAlquiler[],int tAlqui);
int tienePedidoJuego(int idAIgualar,eAlquiler vecAlquiler[],int tAlqui);




/***LOS QUE ME PUEDEN LLEGAR A TOMAR***/

void clienteConMasAlquiler(eCliente vecCliente[],int tCli,
                           eAlquiler vecAlquiler[],int tAlqui,
                           eJuego vecJuego[],int tJue,
                           eCategoria vecCategoria[],int tCate,
                           eLocalidad vecLocalidad[],int tLoca);

int tieneMayorAlquiler(eAlquiler vecAlquiler[],int tAlqui,int idClienteAIgualar);

void listarClientesConXAlquileres(eCliente vecCliente[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                                  eLocalidad vecLocalidad[],int tLoca);

void listarMujeresQueAlquilaron(eCliente vecCliete[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                                eLocalidad vecLocalidad[],int tLoca);

void listarMujeresQueAlquilaronJuegosDeXCategoria(eCliente vecCliete[],int tCli,
                                        eAlquiler vecAlquiler[],int tAlqui,
                                        eJuego vecJuego[],int tJue,
                                        eCategoria vecCategoria[],int tCate,
                                        eLocalidad vecLocalidad[],int tLoca);



void listarClientesPorFecha(eCliente vecClinte[],int tCli,eAlquiler vecAlquiler[],int tAlqui,
                            eLocalidad vecLocalidad[],int tLoca);

int buscarPorFechaAlquiler(eAlquiler vecAlquiler[],eAlquiler auxAlqui,int tAlqui);



