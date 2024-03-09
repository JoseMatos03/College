## Sub-etapas da Modelação Conceitual:

1. **Identificar Entidades-Tipo:**
   - Nesta sub-etapa, o foco é identificar as entidades principais do sistema que será representado na base de dados. Entidades são objetos ou conceitos do mundo real que são significativos para o sistema. Por exemplo, em um sistema de biblioteca, as entidades podem incluir Livro, Autor, Usuário, etc.

2. **Identificar Relacionamentos-Tipo:**
   - Aqui, você determina como as entidades estão relacionadas umas com as outras. Isso envolve entender como as entidades interagem e se conectam no contexto do sistema. Por exemplo, um Livro pode estar relacionado a um Autor através de um relacionamento "Escrito por".

3. **Identificar e Associar Atributos:**
   - Atributos são características ou propriedades das entidades que descrevem detalhes específicos sobre elas. Por exemplo, um Livro pode ter atributos como Título, ISBN, Ano de Publicação, etc. Nesta sub-etapa, você identifica quais atributos são relevantes para cada entidade e os associa a elas.

4. **Definir Domínios de Atributos:**
   - Um domínio de atributo define os valores permitidos para um atributo específico. Por exemplo, o atributo "Ano de Publicação" de um Livro pode ter um domínio de 1900 a 2022. Definir os domínios ajuda a garantir a consistência e integridade dos dados.

5. **Identificar Atributos de Chave Primária:**
   - A chave primária é um atributo ou conjunto de atributos que identifica exclusivamente cada instância de uma entidade. É crucial para garantir a unicidade dos registros. Nesta sub-etapa, você identifica quais atributos servirão como chaves primárias para suas entidades.

6. **Considerar o Uso de Conceitos de Modelação Aprimorada (Opcional):**
   - Esta sub-etapa é opcional e envolve a consideração de conceitos avançados de modelagem, como herança, generalização/especialização, agregação, entre outros. Esses conceitos podem ser úteis para modelar relações mais complexas entre as entidades.

7. **Verificar se Há Redundância:**
   - Durante esta etapa, você verifica se há redundância nos atributos ou relacionamentos identificados. A redundância pode levar a problemas de integridade e eficiência nos dados.

8. **Validar as Transações do Utilizador:**
   - É importante garantir que as transações que os utilizadores do sistema realizarão possam ser adequadamente modeladas com as entidades e relacionamentos definidos.

9. **Rever e Validar o Modelo Conceitual:**
   - Por fim, antes de avançar para a Modelação Lógica, é essencial revisar e validar o modelo conceitual. Isso envolve verificar se o modelo captura corretamente os requisitos do sistema, se todas as entidades, relacionamentos e atributos estão adequadamente definidos e se não há ambiguidades ou erros.
