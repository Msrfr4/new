1. File Comparison:
the function compare two files either character-by-character or word-by word. first it asks you to enter the file paths for both files and ensures they're correct. If not, it let you to re enter the paths then it asks how you want to compare the files—character by character or word by word.
In Character Comparison: It reads each character from both files the while loop loops on all of the characters in one file and the get the author character from the other file and compare them. If there's a mismatch, it tells you where they differ.
in Word Comparison: It the same logic of character comparison but instead it compare the word in the first file with the one in the other file. It knows the line by checking if we reach a new line and Increment the i by one.
after it's ends I clear and set the file to the index 0 and finally, it closes both files.

2. Fractal Pattern:
First it checks if the base case (n==1) is met, then prints a single star. If not it recursively calls itself to draw the upper half of the pattern, prints the middle row of stars, and then calls itself again for the lower half.

3. Inclusive Speech:
The function starts by asking you to input a sentence. It processes each word in the sentence, and if it finds any of the male pronouns ("he", "him", "his", or "himself"), it replaces them with: "he or she", "him or her", "his or hers", or "himself or herself".
The function builds each word one character at a time, and when it encounters a space or punctuation mark (like a period, comma, or exclamation point), it checks if the word matches one of the male pronouns. If there’s a match, it change the sentence. If there’s no match, the original word is appended.

4. Scoreboard:
add a player’s name and score:
 The function maintains a sorted list of up to 10 players with the highest scores. After each addition, the list is sorted in descending order based on the scores. If there are more than 10 players, the player with the lowest score is removed to keep only the top 10 players in the list.
search for a player's score:
  The function checks if the player is in the list and, if found, displays their score. If the player is not found, it informs you that the player’s name is not in the list.
print scoreboard:
 up to 10 players can be printed, showing each player’s name and their score in descending order.
The function loops through these options (adding players, searching, and printing) until you choose to exit. It ensures that the list is always up-to-date and maintains only the top 10 scores.

