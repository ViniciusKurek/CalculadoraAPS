### INICIALIZAÇÃO
- Para compilar basta digitar ``make`` no terminal dentro do diretório raiz;
- Para executar basta digitar ``./main`` caso esteja no windows, e ``./main.exe`` caso esteja no linux;

### FUNCIONALIDADES
- Neste projeto cumprimos as seguintes funcionalidades descritas nos casos de uso do projeto:

    - <b>Enviar feedback do formulário:</b> O administrador deve ser capaz de dar um feedback de um formulário enviado por um proprietário (4 pontos);

    - <b>Ver feedback do formulário:</b> O proprietário deve ser capaz de ver um feedback de uma etapa de um de seus projetos, escrita pelo administrador (5 pontos);

### IMPLEMENTAÇÕES
- Para o sistema funcionar como queríamos, os DAOs precisaram ser estáticos, pois era neles que ficava o repositório de objetos de determinado conceito, consequentemente, só poderia haver um único DAO de cada tipo no sistema inteiro, e quem gerencia isso é o <b>DAOManager</b>. Entendemos que no mundo real isso não deveria ser feito, já que usariamos conexão com o banco de dados e cada DAO compartilharia do mesmo repositório.