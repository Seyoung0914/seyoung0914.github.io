package edu.handong.csee.java.hw3.shapes;

/**
 * The Rectangle class represents a rectangle in 2D space with an origin point, width, and height.
 */
public class Rectangle {
    private int width = 0; // width of the rectangle
    private int height = 0; // height of the rectangle
    private Point origin; // origin point of the rectangle
    
    /**
     * Constructs a new Rectangle object with width and height initialized to 0 and origin at (0,0).
     */
    public Rectangle(){
        origin = new Point(0,0);
    }
    
    /**
     * Constructs a new Rectangle object with the specified origin point.
     * @param p the origin point of the rectangle
     */
    public Rectangle(Point p){
        origin = p;
    }
    
    /**
     * Constructs a new Rectangle object with the specified width and height, and origin at (0,0).
     * @param w the width of the rectangle
     * @param h the height of the rectangle
     */
    public Rectangle(int w, int h){
        origin = new Point(0,0);
        width = w;
        height = h;
    }

    /**
     * Constructs a new Rectangle object with the specified origin point, width, and height.
     * @param p the origin point of the rectangle
     * @param w the width of the rectangle
     * @param h the height of the rectangle
     */
    public Rectangle(Point p, int w, int h){
        origin = p;
        width = w;
        height = h;
    }

    /**
     * Moves the rectangle to the specified position.
     * @param x the x-coordinate of the new position
     * @param y the y-coordinate of the new position
     */
    public void move(int x, int y) {
        origin.setX(x);
        origin.setY(y);
    }

    /**
     * Computes and returns the area of the rectangle.
     * @return the area of the rectangle
     */
    public int getArea(){
        return width * height;
    }

    /**
     * Gets the width of the rectangle.
     * @return the width of the rectangle
     */
    public int getWidth() {
        return width;
    }
    
    /**
     * Sets the width of the rectangle.
     * @param width the new width to set
     */
    public void setWidth(int width){
        this.width = width;
    }

    /**
     * Gets the height of the rectangle.
     * @return the height of the rectangle
     */
    public int getHeight(){
        return height;
    }
    
    /**
     * Sets the height of the rectangle.
     * @param height the new height to set
     */
    public void setHeight(int height){
        this.height = height;
    }  

    /**
     * Gets the origin point of the rectangle.
     * @return the origin point of the rectangle
     */
    public Point getPoint(){
        return origin;
    }   

    /**
     * Sets the origin point of the rectangle.
     * @param origin the new origin point to set
     * @return the new origin point
     */
     public Point setPoint(Point origin){
        this.origin = origin;
        return origin;
    }
}
