package HashExperimentation;
import java.util.*; //all utility methods

public class Movie {

    private String name;
    private String director;
    private String rating;
    private int duration;


    //constructor
    public Movie(String name, String director, String rating, int duration){
        this.name = name;
        this.director = director;
        this.rating = rating;
        this.duration = duration;
    }

    //default constructor - so we can make random names 
    public Movie() {
        //x = generate a random number between 1 and 30
        //generate x random characters
        Random random = new Random(); //random number between 0 and 1
        int nameLength = (int) (30 * random.nextDouble()); //tells us how long name can be (between 0 and 29 characters long)
        //generate movie title
        char nameChars[] = new char[nameLength]; //create a char array that will nave nameLength amount spots in it
        for(int index = 0; index < nameLength; index++) { //walk through every entry within the char array
            nameChars[index] = (char) ('a' + (int) (random.nextDouble() * 26)); //generate random char for each entry in array between a and z
        }
        this.name = new String(nameChars); //turn char array into a string
        this.director = "?";
        this.rating = "?";
        this.duration = 0;
    }

    public String getName() {
        return(name);
    }

    public String getDirector() {
        return(director);
    }

    public String getRating() {
        return(rating);
    }

    public String getDuration() {
        return(duration);
    }

    //overriding the build in method toString so we dont get Movie@xxxxxx
    public String toString() {
        String result = 
        "(" + 
        "'" + name + "', " +
        director + ", " + 
        rating + ", " +
        duration + ", " +
        "#" + hashCode() +
        ")";
        return(result);
    }

    public int hashCode() {
        //take a movie object and turn it into a number
        //number must be deterministiaclly defined; not random
        //want the number to be generated to be 'random' equally likely to be between 0 and n
        //exorcist must always hash to the same number

        //convert name into  natural number using ASCII values
        return (hashCode(name));
    }

    //this allows us give access to hashCode to other classes.
    //So outside classes now have the ability to generate a hash code using the same techniwue that this class 
    //usesd to generate its hash code.
    public static int hashCode(String name) { //static means it belongs to the class. Doesnt belong to an object. Can call w/o constructing an object
        int result = 0; 
        for(int index = 0; index < name.length(); index++) {
            result += name.charAt(index); //returns a number of the char using ASCII table
        }
        
        return(result);
    }
}
