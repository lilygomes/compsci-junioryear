public class Geometry {
	/**
	 * Returns volume of sphere with given dimensions.
	 * @param r Radius
	 */
	public static double sphereVolume(double r) {
		// (4 / 3) * pi * r³
		return (4.0/3.0) * Math.PI * Math.pow(r, 3);
	}

	/**
	 * Returns surface area of sphere with given dimensions.
	 * @param r Radius
	 */
	public static double sphereSurface(double r) {
		// 4 * pi * r²
		return 4.0 * Math.PI * Math.pow(r, 2);
	}

	/**
	 * Returns volume of cylinder with given dimensions.
	 * @param r Radius
	 * @param h Height
	 */
	public static double cylinderVolume(double r, double h) {
		// (pi * r²) * h
		return (Math.PI * Math.pow(r, 2)) * h;
	}

	/**
	 * Returns surface area of cylinder with given dimensions.
	 * @param r Radius
	 * @param h Height
	 */
	public static double cylinderSurface(double r, double h) {
		// 2 * pi * r * (h + r)
		return 2 * Math.PI * r * (h + r);
	}

	/**
	 * Returns volume of cone with given dimensions.
	 * @param r Radius
	 * @param h Height
	 */
	public static double coneVolume(double r, double h) {
		// (pi * r² * h) / 3
		return (Math.PI * Math.pow(r, 2) * h) / 3;
	}

	/**
	 * Returns area of cone with given dimensions.
	 * @param r Radius
	 * @param h Perpendicular height
	 */
	public static double coneSurface(double r, double h) {
		// pi * r * s (slant height, solved for using pythagorean theorem) + pi * r²
		return Math.PI * r * Math.sqrt(Math.pow(r, 2) + Math.pow(h, 2)) + (Math.PI * Math.pow(r, 2));
	}
}
