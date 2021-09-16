import java.util.Scanner;

public class GeometryCalculator {
	public static void main(String[] args) {
		// Scanner for system input
		Scanner kbd = new Scanner(System.in);
		// Get radius from user input
		System.out.println("Enter radius:");
		double r = kbd.nextDouble();
		// Get height from user input
		System.out.println("Enter height:");
		double h = kbd.nextDouble();
		// Output all possible surface areas and volumes of given objects
		System.out.println("The volume of the sphere is: " + Geometry.sphereVolume(r));
		System.out.println("The surface area of the sphere is: " + Geometry.sphereSurface(r));
		System.out.println("The volume of the cylinder is: " + Geometry.cylinderVolume(r, h));
		System.out.println("The surface area of the cylinder is: " + Geometry.cylinderSurface(r, h));
		System.out.println("The volume of the cone is: " + Geometry.coneVolume(r, h));
		System.out.println("The surface area of the cone is: " + Geometry.coneSurface(r, h));
		// Stop kbd from leaking
		kbd.close();
	}
}
