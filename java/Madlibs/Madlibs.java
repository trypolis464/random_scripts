/*
 * Madlibs.
 * Basic madlibs app in Java, initially written for a high school programming class.
 * 
 * Copyright (C) 2021, Ty Gillespie. All rights reserved.
 * MIT License.
 */

import java.util.Scanner;

public class Madlibs {
    public static Scanner keyboardInput = new Scanner(System.in);

    public static void main(String args[]) {
        System.out.print("Enter color: ");
        String color = keyboardInput.nextLine();
        System.out.print("Enter plural noun: ");
        String pluralNoun = keyboardInput.nextLine();
        System.out.print("Enter celebrity: ");
        String celebrity = keyboardInput.nextLine();
        System.out.println("Roses are " + color);
        System.out.println(pluralNoun + " are blue");
        System.out.println("I love " + celebrity);
    }
}
