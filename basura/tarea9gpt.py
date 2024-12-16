from itertools import permutations

def clash_of_cards(k, cases):
    results = []
    
    for case in cases:
        # Read the cards
        C1, C2, C3, C4, C5 = case
        dealt_cards = {C1, C2, C3, C4, C5}
        einer_cards = [C1, C2, C3]
        eduardo_cards = [C4, C5]
        
        # Flag to check if a solution exists
        found = False
        for C6 in range(1, 53):
            if C6 in dealt_cards:
                continue  # Skip already dealt cards
            
            # Add C6 to Eduardo's cards
            all_eduardo_cards = eduardo_cards + [C6]
            
            # Simulate all permutations of card playing order
            eduardo_wins = True
            for eduardo_perm in permutations(all_eduardo_cards, 3):
                for einer_perm in permutations(einer_cards, 3):
                    eduardo_score = sum(e > a for e, a in zip(eduardo_perm, einer_perm))
                    if eduardo_score < 2:  # Eduardo doesn't win this game
                        eduardo_wins = False
                        break
                if not eduardo_wins:
                    break
            
            if eduardo_wins:
                results.append(C6)
                found = True
                break
        
        if not found:
            results.append("NO WAY")
    
    return results

# Input processing
k = 4
cases = [
    [27, 51, 29, 52, 50],
    [10, 20, 30, 23, 27],
    [36, 38, 39, 37, 40],
    [40, 26, 1, 17, 27]
]

# Solve and output
output = clash_of_cards(k, cases)
for result in output:
    print(result)

