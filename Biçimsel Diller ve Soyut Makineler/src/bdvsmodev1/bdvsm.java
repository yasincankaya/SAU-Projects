package bdvsmodev1;
import java.util.*;

public class bdvsm {
    // DFA Tanımı
    static class DFA {
        Set<String> states; // Durumlar kümesi
        Set<String> alphabet; // Alfabe (geçiş sembolleri)
        Map<String, Map<String, String>> transitions; // Geçiş fonksiyonu (durum -> sembol -> yeni durum)
        String startState; // Başlangıç durumu
        Set<String> finalStates; // Kabul (sonlu) durumları

        // DFA constructor (başlatıcı fonksiyon)
        public DFA(Set<String> states, Set<String> alphabet, Map<String, Map<String, String>> transitions,
                   String startState, Set<String> finalStates) {
            this.states = states;
            this.alphabet = alphabet;
            this.transitions = transitions;
            this.startState = startState;
            this.finalStates = finalStates;
        }
    }

    // Ulaşılamayan durumları kaldırma fonksiyonu
    public static Set<String> removeUnreachableStates(DFA dfa) {
        Set<String> reachable = new HashSet<>(); // Erişilebilir durumları tutacak küme
        Queue<String> queue = new LinkedList<>(); // BFS için kuyruk
        queue.add(dfa.startState); // Başlangıç durumunu kuyruğa ekle
        reachable.add(dfa.startState); // Başlangıç durumu erişilebilir olarak işaretlenir

        // BFS ile erişilebilir durumları bul
        while (!queue.isEmpty()) {
            String current = queue.poll();
            for (String symbol : dfa.alphabet) { // Her sembol için
                String nextState = dfa.transitions.getOrDefault(current, new HashMap<>()).get(symbol);
                if (nextState != null && !reachable.contains(nextState)) {
                    reachable.add(nextState); // Yeni erişilebilir durumu ekle
                    queue.add(nextState); // Kuyruğa ekle
                }
            }
        }
        return reachable; // Erişilebilir durumları döndür
    }

    // DFA minimizasyonu
    public static DFA minimizeDFA(DFA dfa) {
        // 1. Ulaşılamayan durumları kaldır
        Set<String> reachableStates = removeUnreachableStates(dfa);
        dfa.states.retainAll(reachableStates); // DFA'dan ulaşılamayan durumları kaldır

        // 2. Denk durumları birleştir
        Set<String> nonFinalStates = new HashSet<>(dfa.states);
        nonFinalStates.removeAll(dfa.finalStates); // Final durumlarının dışındaki durumları ayır

        // İlk eşdeğerlik sınıfları (final ve non-final ayırımı)
        List<Set<String>> partitions = new ArrayList<>();
        partitions.add(dfa.finalStates); // Final durumlarını bir grup olarak ekle
        partitions.add(nonFinalStates); // Non-final durumlarını bir grup olarak ekle

        boolean updated;
        do {
            updated = false; // Grupların güncellenip güncellenmediğini izler
            List<Set<String>> newPartitions = new ArrayList<>();

            for (Set<String> group : partitions) {
                Map<Map<String, Integer>, Set<String>> splitMap = new HashMap<>();
                for (String state : group) {
                    // Her durum için geçiş tablosunu temsil eden imza (signature) hesaplanır
                    Map<String, Integer> signature = new HashMap<>();
                    for (String symbol : dfa.alphabet) {
                        String nextState = dfa.transitions.getOrDefault(state, new HashMap<>()).get(symbol);
                        int groupIndex = getGroupIndex(partitions, nextState); // Geçilen durumun hangi gruba ait olduğu bulunur
                        signature.put(symbol, groupIndex);
                    }
                    // Aynı imzaya sahip durumlar aynı alt gruba eklenir
                    splitMap.computeIfAbsent(signature, k -> new HashSet<>()).add(state);
                }
                newPartitions.addAll(splitMap.values()); // Yeni alt gruplar eklenir
            }

            if (newPartitions.size() != partitions.size()) { // Eğer yeni gruplar oluşmuşsa güncelleme yapılmıştır
                updated = true;
            }
            partitions = newPartitions; // Partisyonları güncelle
        } while (updated); // Gruplar sabitlenene kadar devam et

        // Yeni durumlar ve geçişler oluştur
        Map<String, String> stateMapping = new HashMap<>(); // Eski durum -> Yeni temsilci durum eşlemesi
        Set<String> newStates = new HashSet<>(); // Yeni durumlar kümesi
        Set<String> newFinalStates = new HashSet<>(); // Yeni final durumları kümesi
        String newStartState = null;

        for (Set<String> group : partitions) {
            String representative = group.iterator().next(); // Her grubun temsilci durumunu al
            newStates.add(representative);
            if (group.contains(dfa.startState)) newStartState = representative; // Yeni başlangıç durumu belirlenir
            if (!Collections.disjoint(group, dfa.finalStates)) newFinalStates.add(representative); // Eğer grup final durum içeriyorsa
            for (String state : group) {
                stateMapping.put(state, representative); // Eski durumları yeni temsilcilere eşle
            }
        }

        Map<String, Map<String, String>> newTransitions = new HashMap<>(); // Yeni geçiş tablosu
        for (String state : newStates) {
            newTransitions.put(state, new HashMap<>());
            for (String symbol : dfa.alphabet) {
                String nextState = dfa.transitions.getOrDefault(state, new HashMap<>()).get(symbol);
                if (nextState != null) {
                    newTransitions.get(state).put(symbol, stateMapping.get(nextState)); // Yeni durumlarla geçiş ekle
                }
            }
        }

        return new DFA(newStates, dfa.alphabet, newTransitions, newStartState, newFinalStates); // Minimize edilmiş DFA döndür
    }

    // Bir durumun hangi gruba ait olduğunu bulan yardımcı fonksiyon
    private static int getGroupIndex(List<Set<String>> partitions, String state) {
        for (int i = 0; i < partitions.size(); i++) {
            if (state != null && partitions.get(i).contains(state)) {
                return i; // Durum bulunduğu grubun indeksini döndür
            }
        }
        return -1; // Durum bulunamazsa
    }

    // Test
    public static void main(String[] args) {
        // DFA tanımı
        Set<String> states = new HashSet<>(Arrays.asList("Q0", "Q1", "Q2", "Q3", "Q4" , "Q5"));
        Set<String> alphabet = new HashSet<>(Arrays.asList("0", "1"));
        Map<String, Map<String, String>> transitions = new HashMap<>();
        transitions.put("Q0", Map.of("0", "Q3", "1", "Q1"));
        transitions.put("Q1", Map.of("0", "Q2", "1", "Q5"));
        transitions.put("Q2", Map.of("0", "Q2", "1", "Q5"));
        transitions.put("Q3", Map.of("0", "Q0", "1", "Q4"));
        transitions.put("Q4", Map.of("0", "Q2", "1", "Q5"));
        transitions.put("Q5", Map.of("0", "Q5", "1", "Q5"));
        String startState = "Q0";
        Set<String> finalStates = new HashSet<>(Set.of("Q1", "Q2", "Q4"));

        // DFA oluştur
        DFA dfa = new DFA(states, alphabet, transitions, startState, finalStates);

        // Orijinal DFA'yı yazdır
        System.out.println("Original DFA:");
        System.out.println("States: " + dfa.states);
        System.out.println("Transitions: " + dfa.transitions);
        System.out.println("Final States: " + dfa.finalStates);

        // Minimize DFA'yı oluştur ve yazdır
        DFA minimizedDFA = minimizeDFA(dfa);

        System.out.println("\nMinimized DFA:");
        System.out.println("States: " + minimizedDFA.states);
        System.out.println("Transitions: " + minimizedDFA.transitions);
        System.out.println("Final States: " + minimizedDFA.finalStates);
    }
}
