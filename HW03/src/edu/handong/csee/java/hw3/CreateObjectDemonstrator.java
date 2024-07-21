    package edu.handong.csee.java.hw3;
    import edu.handong.csee.java.hw3.shapes.Point;
    import edu.handong.csee.java.hw3.shapes.Rectangle;

/**
     * CreateObjectDemonstrator class demonstrates the usage of Point and Rectangle classes.
     */
    public class CreateObjectDemonstrator {

        /**
         * Main method, entry point of the program.
         * @param args command-line arguments (not used)
         */
        public static void main(String[] args) {

            // Declare and create a point object and two rectangle objects.
            Point originOne = new Point(23, 94);
            Rectangle rectOne = new Rectangle(originOne, 100, 200);
            Rectangle rectTwo = new Rectangle(50, 100);
        
            // display rectOne's width, height, and area
            System.out.println("Width of rectOne: " + Integer.toString(rectOne.getWidth())/*rectOne.width*/);
            System.out.println("Height of rectOne: " + Integer.toString(rectOne.getHeight())/*rectOne.height*/);
            System.out.println("Area of rectOne: " + rectOne.getArea());
        
            // set rectTwo's position
            rectTwo.setPoint(originOne);
            // rectTwo.origin = originOne;

            // display rectTwo's position
            System.out.println("X Position of rectTwo: " + Integer.toString(rectTwo.getPoint().getX())/*rectTwo.origin.x*/);
            System.out.println("Y Position of rectTwo: " + Integer.toString(rectTwo.getPoint().getY())/*rectTwo.origin.y*/);
        
            // move rectTwo and display its new position
            rectTwo.move(40, 72);
            System.out.println("X Position of rectTwo: " + Integer.toString(rectTwo.getPoint().getX())/*rectTwo.origin.x*/);
            System.out.println("Y Position of rectTwo: " + Integer.toString(rectTwo.getPoint().getY())/*rectTwo.origin.y*/);
        }
    }
