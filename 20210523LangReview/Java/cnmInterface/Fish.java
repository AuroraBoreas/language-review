package cnmInterface;

public class Fish implements Prey, Predator {
	@Override
	public void hunt() {
		System.out.println("small fishes are delicious!");
	}
	
	@Override
	public void flee() {
		System.out.println("*big fish inc! run!*");
	}
}
