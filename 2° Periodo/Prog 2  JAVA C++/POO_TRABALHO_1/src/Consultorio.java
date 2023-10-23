import java.util.ArrayList;

public class Consultorio {
    private ArrayList<Medico> medicos;
    private ArrayList<Paciente> pacientes;
    private ArrayList<Consulta> consultas;
    private int id;

    public Consultorio() {
        this.medicos = new ArrayList<Medico>();
        this.consultas = new ArrayList<Consulta>();
        this.pacientes = new ArrayList<Paciente>();
        id = 0;
    }

    public void cadastrarPaciente(Paciente p) {
        for (Paciente i : pacientes)
            if (i.getCpf().equals(p.getCpf())) {
                System.out.println("Paciente já Cadastrado");
                return;
            }
        pacientes.add(p);
        System.out.println("Paciente Cadastrado");
    }

    public void removerPaciente(String cpf) {
        for (Paciente i : pacientes)
            if (i.getCpf().equals(cpf)) {
                pacientes.remove(i);
                System.out.println("Paciente Removido");
                return;
            }
        System.out.println("Paciente não Encontrado");
    }

    public void cadastrarMedico(Medico m) {
        for (Medico i : medicos)
            if (i.getCrm() == m.getCrm()) {
                System.out.println("Medico já Cadastrado");
                return;
            }
        medicos.add(m);
        System.out.println("Medico Cadastrado");
    }

    public void removerMedico(int crm) {
        for (Medico i : medicos)
            if (i.getCrm() == crm) {
                medicos.remove(i);
                System.out.println("Medico Removido");
                return;
            }
        System.out.println("Medico não Encontrado");
    }

    public void verificarId() {
        if (id == 500)
            id = 0;
        else
            id++;
    }

    public void cadastrarConsulta(Consulta c) {

        for (Consulta i : consultas) {
            if (i.getData().equals(c.getData()) && i.getHora().equals(c.getHora())
                    && i.getCpfPaciente().equals(c.getCpfPaciente()) && i.getCrmMedico() == c.getCrmMedico()) {
                System.out.println("Consulta já Cadastrado");
                return;
            } else if (i.getData().equals(c.getData()) && i.getHora().equals(c.getHora())
                    && i.getCrmMedico() == c.getCrmMedico()) {
                System.out.println("Horario já utilizado pelo Medico");
                return;
            }
        }

        for (Medico i : medicos) {
            if (i.getCrm() == c.getCrmMedico()) {
                for (Paciente j : pacientes) {
                    if (j.getCpf().equals(c.getCpfPaciente())) {

                        c.setId(id);
                        verificarId();

                        consultas.add(c);
                        System.out.println("Consulta Cadastrado");
                        c.imprimir();
                        return;
                    }
                }
            }
        }

        System.out.println("Medico ou Pacinete não Cadastrado");
    }

    public void removerConsulta(int id, int crmMedico, String cpfPaciente) {

        for (Consulta i : consultas)
            if (i.getCrmMedico() == crmMedico && i.getId()==id && i.getCpfPaciente().equals(cpfPaciente)){
                consultas.remove(i);
                System.out.println("Consulta Removido");
                return;
            }
        System.out.println("Consulta não Encontrado");
    }

    public void imprimirListaPacientes() {
        if (pacientes.isEmpty()) {
            System.out.println();
            System.out.println("Nenhum Paciente Cadastrado\n");
            return;
        }

        for (Paciente i : pacientes) {
            i.imprimir();
            System.out.println("\n");
        }
    }

    public void imprimirListaMedicos() {
        if (medicos.isEmpty()) {
            System.out.println();
            System.out.println("Nenhum Medico Cadastrado");
            return;
        }
        for (Medico i : medicos) {
            i.imprimir();
            System.out.println("\n");
        }
    }

    public void imprimirListaConsultas() {
        if (consultas.isEmpty()) {
            System.out.println();
            System.out.println("Nenhum Consulta Cadastrada");
            return;
        }
        for (Consulta i : consultas) {
            i.imprimir();
            System.out.println("\n");
        }
    }

    public void imprimirConsulta(String cpfPaciente, int crmMedico, int id) {
        for (Consulta i : consultas) {
            if (i.getCpfPaciente().equals(cpfPaciente) && i.getCrmMedico() == crmMedico && i.getId()==id) {
                i.imprimir();
                return;
            }
        }
        System.out.println("Consulta não encontrado!\n");
    }
}
