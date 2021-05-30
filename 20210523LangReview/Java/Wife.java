
public class Wife {
	private String m_name;
	private int m_age;
	
	public Wife() {
		m_name = "TS";
		m_age = 18;
	}
	
	public Wife(String name, int age) {
		m_name = name;
		m_age = age;
	}
	
	public String toString() {
		return String.format("\nname : %s\nage: %s", m_name, m_age);
	}
}