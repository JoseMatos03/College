package uminho.dss.turmas3l.data;

import uminho.dss.turmas3l.business.Aluno;

import java.sql.*;
import java.util.Collection;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

import static java.util.stream.Collectors.toList;

public class AlunoDAO implements Map<String, Aluno> {
    private static AlunoDAO singleton = null;

    private AlunoDAO() {
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement()) {
            String sql = "CREATE TABLE IF NOT EXISTS alunos (" +
                    "Num varchar(10) NOT NULL PRIMARY KEY," +
                    "Nome varchar(45) DEFAULT NULL," +
                    "Email varchar(45) DEFAULT NULL," +
                    "Turma varchar(10), foreign key(Turma) references turmas(Id))";
            stm.executeUpdate(sql);
        } catch (SQLException e) {
            // Erro a criar tabela...
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
    }

    public static AlunoDAO getInstance() {
        if (AlunoDAO.singleton == null) {
            AlunoDAO.singleton = new AlunoDAO();
        }
        return AlunoDAO.singleton;
    }

    @Override
    public int size() {
        int i = 0;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement();
             ResultSet rs = stm.executeQuery("SELECT count(*) FROM alunos")) {
            if(rs.next()) {
                i = rs.getInt(1);
            }
        }
        catch (Exception e) {
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return i;
    }

    @Override
    public boolean isEmpty() {
        return this.size() == 0;
    }

    @Override
    public boolean containsKey(Object key) {
        boolean r;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             PreparedStatement pstm = conn.prepareStatement("SELECT Num FROM alunos WHERE Num=?")) {
            pstm.setString(1, key.toString());
            try (ResultSet rs = pstm.executeQuery()) {
                r = rs.next();  // A chave existe na tabela
            }
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return r;
    }

    @Override
    public boolean containsValue(Object value) {
        Aluno a = (Aluno) value;
        return this.containsKey(a.getNumero());
    }

    @Override
    public Aluno get(Object key) {
        Aluno a = null;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             PreparedStatement pstm = conn.prepareStatement("SELECT * FROM alunos WHERE Num=?")) {
            pstm.setString(1, key.toString());
            try (ResultSet rs = pstm.executeQuery()) {
                if (rs.next()) {  // A chave existe na tabela
                    String num = rs.getString("Num");  // Podíamos usar a key, mas assim temos a certeza que é o id da BD
                    String nome = rs.getString("Nome");
                    String email = rs.getString("Email");

                    // Construir aluno
                    a = new Aluno(num, nome, email);
                }
            }
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return a;
    }

    @Override
    public Aluno put(String key, Aluno a) {
        Aluno res = null;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement()) {

            // Verificar se o aluno já existe
            PreparedStatement pstm = conn.prepareStatement("SELECT Num FROM alunos WHERE Num=?");
            pstm.setString(1, key);
            ResultSet rs = pstm.executeQuery();

            if (rs.next()) {
                // Atualizar
                PreparedStatement pstm2 = conn.prepareStatement("UPDATE alunos SET Nome=?, Email=?, Turma=? WHERE Num=?");
                pstm2.setString(1, a.getNome());
                pstm2.setString(2, a.getEmail());
                pstm2.setString(4, a.getNumero());
                pstm2.executeUpdate();
                res = a;
            } else {
                // Inserir
                PreparedStatement pstm2 = conn.prepareStatement("INSERT INTO alunos VALUES (?,?,?,?)");
                pstm2.setString(1, a.getNumero());
                pstm2.setString(2, a.getNome());
                pstm2.setString(3, a.getEmail());
                pstm2.setString(4, "1");
                pstm2.executeUpdate();
                res = a;
            }

        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return res;
    }

    @Override
    public Aluno remove(Object key) {
        Aluno a = this.get(key);
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             PreparedStatement pstm = conn.prepareStatement("DELETE FROM alunos WHERE Num=?")) {
            pstm.setString(1, key.toString());
            pstm.executeUpdate();
        } catch (Exception e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return a;
    }

    @Override
    public void putAll(Map<? extends String, ? extends Aluno> alunos) {
        for(Aluno a : alunos.values()) {
            this.put(a.getNumero(), a);
        }
    }

    @Override
    public void clear() {
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement()) {
            stm.executeUpdate("DELETE * FROM alunos");
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
    }

    @Override
    public Set<String> keySet() {
        Set<String> r = null;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement();
             ResultSet rs = stm.executeQuery("SELECT Num FROM alunos")) {
            r = new TreeSet<>();
            while (rs.next()) {
                r.add(rs.getString("Num"));
            }
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return r;
    }

    @Override
    public Collection<Aluno> values() {
        Collection<Aluno> col = new HashSet<>();
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement();
             ResultSet rs = stm.executeQuery("SELECT Num FROM alunos")) {
            while (rs.next()) {
                col.add(this.get(rs.getString("Num")));
            }
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return col;
    }

    @Override
    public Set<Entry<String, Aluno>> entrySet() {
        Set<Entry<String, Aluno>> r = null;
        try (Connection conn = DriverManager.getConnection(DAOconfig.URL, DAOconfig.USERNAME, DAOconfig.PASSWORD);
             Statement stm = conn.createStatement();
             ResultSet rs = stm.executeQuery("SELECT Num FROM alunos")) {
            r = new HashSet<>();
            while (rs.next()) {
                String key = rs.getString("Num");
                Aluno value = this.get(key);
                r.add(new Entry() {
                    @Override
                    public String getKey() {
                        return key;
                    }

                    @Override
                    public Aluno getValue() {
                        return value;
                    }

                    @Override
                    public Object setValue(Object value) {
                        return put(key, (Aluno) value);
                    }
                });
            }
        } catch (SQLException e) {
            // Database error!
            e.printStackTrace();
            throw new NullPointerException(e.getMessage());
        }
        return r;
    }
}
