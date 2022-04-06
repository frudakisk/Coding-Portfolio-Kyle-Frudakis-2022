package HashExperimentation;
//open address table with probing
//auxiliary hash function is like the division method
//hash function becomes auxiliary hash function plus the probing function
//key and probe start
public class MovieTable {
    
    private Movie table[]; //this is an array of Movie objects. table is a pointer to Movie objects

    public MovieTable(int m) {
        //m is number of entries into our hash table
        //construct an array with m entries in it
        this.table = new Movie[m];
    }

    private int auxiliaryHash(int hashCode) {
        //want to use the division number
        //this is our native hash function because we are using things like division method or multiplication method
        int result = hashCode % table.length; //table.length is the same as m
        return(result);
    }

    private int hash(String name, int probeCount) {
        //this is our hash function
        double c1 = 9.8765; //for quadratic probing
        double c2 = 5.7832; //for quadratic probing
        int hashCode = Movie.hashCode(name); //convert to a natural number
        double probeResult = c1*probeCount + c2*probeCount*probeCount; //quadratic
        //for linear we would have int result = (auxiliaryHash(hashCode) + probeCount) % table.length;
        int result = (auxiliaryHash(hashCode) + (int)probeResult) % table.length; //quadratic
        //use mod so we get withing table length slots
        //hashcode creates the original number interpretation of the name
        //we use the auxiliaryHash bc it is h(k) and not k (hashCode is k)... just how probing works
        //probecount we will have to see idk yet...
        return (result);
    }

    public boolean contains(String name) {
        //returns true of the name of the movie is within the table
        int probeCount = 0; //probecount is initially 0 bc initially we dont do probing, only when there is a collision
        int slot = hash(name, probeCount);
        while((probeCount < table.length) &&
              (table[slot] != null) && 
              (!table[slot].getName().equals(name))) {
            //increase the probe count and recompute the hash
            probeCount ++;
            slot = hash(name, probeCount);
        }
        if((table[slot] != null) &&
            (table[slot].getName().equals(name))) {
            return(true);
        }
        return(false);

    }



    public void add(Movie movie) {
        //adding a movie into our table
        //must have hash function
        int probeCount = 0; //probecount is initially 0 bc initially we dont do probing, only when there is a collision
        int slot = hash(movie.getName(), probeCount);
        while(table[slot] != null) {
            //while i have a collision
            //increase the probe count and recompute the hash
            probeCount ++;
            slot = hash(movie.getName(), probeCount);
        }
        //if(table[slot] == null) {
        table[slot] = movie; //if the slot is empty, we add in our movie number 
        //}
        //else {
        //   System.out.println("Table Collision!");
        //}
    }


    public String toString() { //another override so we dont get MovieTable@xxxxxx in our table
        String result = "";
        int maxColumns = 40;
        int numberRows = table.length / maxColumns;
        for(int rowCount = 0; rowCount < numberRows; rowCount++) {
            for(int colIndex = 0; colIndex < maxColumns; colIndex++) {
                if(table[rowCount*maxColumns + colIndex] == null) {
                    result += "-";
                } else {
                    result += "*";
                }
            }
            result += "\n";
        }
        return(result);
    }

    private int getMaximumChain() {
        //walk table left from right
        //keep track of when you are in a chain and when you leave one
        //keep track if that chain length is bigger than maximum
        int maxChainLength = 0;
        int currentChainLength = 0;
        boolean inChain = false;

        for(int index = 0; index < table.length; index++) {
            if(table[index] != null) {
                inChain = true;
                currentChainLength ++;
            } else {
                //null slot i am in
                if(inChain) {
                    if(currentChainLength > maxChainLength) {
                        maxChainLength = currentChainLength;
                    }
                }
                inChain = false;
                currentChainLength = 0;
            }
        }
        if(inChain) {
            if(currentChainLength > maxChainLength) {
                maxChainLength = currentChainLength;
            }
        }

        return(maxChainLength);
    }

    private double getAverageChain() {
        int totalChainLength = 0; //number of elements basically
        int currentChainLength = 0;
        int numberOfChains = 0; //number of chains existing in table (chain can be just one object) should ne <= totalChainLength
        boolean inChain = false;

        for(int index = 0; index < table.length; index++) {
            if(table[index] != null) {
                inChain = true;
                currentChainLength ++;
            } else {
                //null slot i am in
                if(inChain) {
                    totalChainLength += currentChainLength;
                    numberOfChains ++;
                }
                inChain = false;
                currentChainLength = 0;
            }
        }
        if(inChain) {
            totalChainLength += currentChainLength;
            numberOfChains ++;
        }

        return((double) totalChainLength / numberOfChains);
    }

    public String getStatistics() {
        String result = "";
        result += "max chain length = " + getMaximumChain();
        result += "\naverage chain length = " + getAverageChain();
        return(result);
    }
    /*
    public String toString() { //another override so we dont get MovieTable@xxxxxx in our table
        String result = "[\n";
        for(int index = 0; index < table.length; index++) {
            result += index + ": ";
            if(table[index] == null) {
                result += "<empty>\n";
            }
            else {
                result += table[index] + "\n";
            }
        }

        result += "]\n";
        return(result);
    }
    */
}
