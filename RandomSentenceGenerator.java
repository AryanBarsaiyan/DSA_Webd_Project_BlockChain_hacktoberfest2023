import java.util.*;

public class RandomSentenceGenerator {

    private Map<String, List<String>> grammar;

    public RandomSentenceGenerator() {
        grammar = new HashMap<>();
    }

    public void addRule(String nonTerminal, String... expansions) {
        grammar.putIfAbsent(nonTerminal, new ArrayList<>());
        grammar.get(nonTerminal).addAll(Arrays.asList(expansions));
    }

    public String generateSentence(String startSymbol) {
        StringBuilder sentence = new StringBuilder();
        expandNonTerminal(startSymbol, sentence);
        return sentence.toString().trim();
    }

    private void expandNonTerminal(String nonTerminal, StringBuilder sentence) {
        if (!grammar.containsKey(nonTerminal)) {
            sentence.append(nonTerminal).append(" ");
            return;
        }

        List<String> expansions = grammar.get(nonTerminal);
        String expansion = expansions.get((int) (Math.random() * expansions.size()));
        String[] symbols = expansion.split("\\s+");

        for (String symbol : symbols) {
            expandNonTerminal(symbol, sentence);
        }
    }

    public static void main(String[] args) {
        RandomSentenceGenerator sentenceGenerator = new RandomSentenceGenerator();

        // Example grammar for simple sentences
        sentenceGenerator.addRule("<sentence>", "<subject> <verb> <object>");
        sentenceGenerator.addRule("<subject>", "I", "You", "He", "She");
        sentenceGenerator.addRule("<verb>", "love", "like", "hate");
        sentenceGenerator.addRule("<object>", "apples", "giraffe", "cats", "dogs");

        // Generate a random sentence
        String sentence = sentenceGenerator.generateSentence("<sentence>");
        System.out.println(sentence);
    }
}

