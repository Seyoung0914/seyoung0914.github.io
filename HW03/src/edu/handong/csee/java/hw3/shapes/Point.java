package edu.handong.csee.java.hw3.shapes;

/**
 * The Point class represents a point in 2D space with integer coordinates.
 */
public class Point {
    private int x = 0; // x-coordinate of the point
    private int y = 0; // y-coordinate of the point
    
    /**
     * Constructs a new Point object with the specified coordinates.
     * @param x the x-coordinate of the point
     * @param y the y-coordinate of the point
     */
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    /**
     * Sets the x-coordinate of the point.
     * @param x the new x-coordinate to set
     */
    public void setX(int x){
        this.x = x;
    }

    /**
     * Gets the x-coordinate of the point.
     * @return the x-coordinate of the point
     */
    public int getX(){
        return x;
    }

    /**
     * Sets the y-coordinate of the point.
     * @param y the new y-coordinate to set
     */
    public void setY(int y){
        this.y = y;
    }
    
    /**
     * Gets the y-coordinate of the point.
     * @return the y-coordinate of the point
     */
    public int getY(){
        return y;
    }
}
