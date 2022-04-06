package HashExperimentation;

public class HashTest {
    //25% = (7,1.68), (19,1.6), (11, 1.6), (8,1.5), (13,1.78) with linear probing
    //25% = (6, 1.30), (5,1.30), (4,1.4), (4,1.26) with quadratic probing

    //50% = (24, 2.7), (19,2.5), (27,2.7), (42, 2.5), (18, 2.5) with linear probing
    //50% = (7, 2.0), (11, 2.1), (9, 1.90), (8, 1.92), (9, 2.1) with quadratic probing
    public static void main(String[] args){
        MovieTable table = new MovieTable(500);

        for(int count = 0; count < 250; count++) {
            table.add(new Movie());
            System.out.println(table);
            System.out.println(table.getStatistics());

            //sleep for 20ms
            try {
                Thread.currentThread().sleep(5);
            } catch(Exception exc) {}
        }

    }

}
