import java.util.ArrayList;

public class Consultorio {
    private ArrayList<Medico> medicos;
    private ArrayList<Paciente> pacientes;
    private ArrayList<Consulta> consultas;

    public Consultorio() {
        this.medicos = new ArrayList<Medico>();
        this.consultas = new ArrayList<Consulta>();
        this.pacientes = new ArrayList<Paciente>();
    }

    public void cadastrarPaciente(Paciente p) {
        for (Paciente i : pacientes)
            if (i.equals(p)) {
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
            if (i.equals(m)) {
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

    public void cadastrarConsulta(Consulta c) {
        for (Consulta i : consultas)
            if (i.equals(c)) {
                System.out.println("Consulta já Cadastrado");
                return;
            }
        consultas.add(c);
        System.out.println("Consulta Cadastrado");
    }

    public void removerConsulta(String cpfPaciente, int crmMedico) {
        for (Consulta i : consultas)
            if (i.getCrmMedico() == crmMedico && i.getCpfPaciente().equals(cpfPaciente)) {
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
            System.out.println("Nenhum Medico Cadastrado\n");
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
            System.out.println("Nenhum Consulta Cadastrada\n");
            return;
        }
        for (Paciente i : pacientes) {
            i.imprimir();
            System.out.println("\n");
        }
    }

}
