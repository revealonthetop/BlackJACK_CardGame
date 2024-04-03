#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// 카드 덱을 초기화하는 함수
void initialize_Deck(vector<int>& deck, int size) {
    for (int i = 0; i < size; ++i) {
        deck.push_back(i % 13 + 1);
    }
}

// 카드를 섞는 함수
void shuffle_Deck(vector<int>& deck) {
    for (int i = 0; i < deck.size(); ++i) {
        int randomIndex = rand() % deck.size();
        swap(deck[i], deck[randomIndex]);
    }
}

// 카드 값을 계산하는 함수 (A는 1 또는 11로 계산)
int calculate_Value(int card) {
    return (card > 10) ? 10 : card;
}

// 플레이어 또는 딜러의 카드 합을 계산하는 함수
int calculate_HandValue(const vector<int>& hand) {
    int sum = 0;
    int numAces = 0;
    for (int card : hand) {
        int value = calculate_Value(card);
        sum += value;
        if (value == 1) {
            numAces++;
        }
    }
    while (sum <= 11 && numAces > 0) {
        sum += 10;
        numAces--;
    }
    return sum;
}

// 게임 결과를 출력하는 함수
void print_Result(int playerTotal, int dealerTotal) {
    if (playerTotal > 21) {
        cout << "플레이어의 숫자가 21을 넘었습니다! 딜러의 승리입니다.\n\n" << endl;
    }
    else if (dealerTotal > 21) {
        cout << "딜러의 숫자가 21을 넘었습니다. 플레이어의 승리입니다.\n\n" << endl;
    }
    else if (playerTotal > dealerTotal) {
        cout << "플레이어의 승리! 패배하셨습니다.\n\n" << endl;
    }
    else if (playerTotal < dealerTotal) {
        cout << "딜러의 승리!!!! 패배하셨습니다.\n\n" << endl;
    }
    else {
        cout << "무승부!" << endl;
    }
}

void explain_Rule() {
    std::cout << "************************************************ 룰 설명 ************************************************\n";
    std::cout << "블랙잭은 카지노 게임 중 하나로, 딜러와 플레이어가 카드를 받아 가까운 합이 21에 가까워지도록 하는 게임입니다.\n";
    std::cout << "각 카드에는 숫자가 부여되며, 숫자 카드는 그 숫자만큼의 값을 가지며, 킹, 퀸, 잭은 각각 10의 값을 가지고, 에이스는 1 또는 11의 값을 가집니다.\n";
    std::cout << "게임은 다음과 같은 단계로 진행됩니다:\n\n";
    std::cout << "1. 딜러가 플레이어와 자신에게 카드를 2장씩 나눠줍니다. 보통 딜러는 한 장은 뒷면으로 두고 한 장은 오픈하여 보여줍니다.\n";
    std::cout << "2. 플레이어는 자신의 카드를 확인한 후, 더 많은 카드를 받을지(hit) 그만 받을지(stop)를 선택합니다.\n";
    std::cout << "3. 플레이어가 카드를 더 이상 받지 않는다면, 딜러는 자신의 카드를 오픈합니다. 딜러는 17 이상의 숫자가 될 때까지 카드를 계속 받습니다.\n";
    std::cout << "4. 딜러와 플레이어의 숫자를 비교하여 승패를 결정합니다. 21에 가까운 숫자를 가진 쪽이 승리하며, 21을 초과하면 패배합니다. 동점일 경우 비깁니다.\n";
    std::cout << "5. 플레이어가 21에 가까운 숫자를 가지고 있으면서 동시에 딜러가 21에 가까운 숫자를 가지고 있지 않다면, 플레이어가 이깁니다.\n\n\n";
}

int main() {
    int continue_num = 2;
    cout << "=======================================================================" << endl;
    cout << "  BBBBB   L        A     CCCCC   K   K   JJJJJ   A     CCCCC   K   K \n";
    cout << "  B    B  L       A A   C        K  K       J   A A   C        K  K  \n";
    cout << "  BBBBB   L      AAAAA  C        KKK        J  AAAAA  C        KKK   \n";
    cout << "  B    B  L      A   A  C        K  K   J   J  A   A  C        K  K  \n";
    cout << "  BBBBB   LLLLL  A   A   CCCCC   K   K   JJJ   A   A   CCCCC   K   K \n";
    cout << "=======================================================================\n\n" << endl;

    do {
        cout << "이용하고자 하는 메뉴의 숫자를 입력하세요\n" << endl;
        cout << "1. 게임시작 \n2. 게임종료 \n3. 룰설명\n\n" << endl;
        cin >> continue_num;

        if (continue_num == 1) {
            srand(time(0)); // 난수 시드 설정

            const int deckSize = 52;
            vector<int> deck;
            initialize_Deck(deck, deckSize);
            shuffle_Deck(deck);

            vector<int> playerHand;
            vector<int> dealerHand;
            int deckIndex = 4;

            // 초기 두 장의 카드를 나눠줌
            playerHand.push_back(deck[0]);
            dealerHand.push_back(deck[1]);
            playerHand.push_back(deck[2]);
            dealerHand.push_back(deck[3]);

            cout << "플레이어가 받은 카드: |"<< deck[0] <<", "<< deck[2] << "|    카드 합 : **" << calculate_HandValue(playerHand) << endl;
            cout << "딜러의 카드 패:       |" << deck[1] << ", " << deck[3] << "|    카드 합 : **" << calculate_HandValue(dealerHand)<< "\n" << endl;

            // 플레이어가 더 이상 카드를 받을지 결정
            char choice;
            cout << "카드를 받으시겠습니까? (y/n): ";
            cin >> choice;

            while (choice == 'y' || choice == 'Y') {
                playerHand.push_back(deck[deckIndex]);
                cout << "[플레이어]가 받은 카드 숫자 : " << deck[deckIndex] << endl;
                deckIndex++;
                cout << "플레이어의 손패값: " << calculate_HandValue(playerHand)<< "\n" << endl;
                if (calculate_HandValue(playerHand) > 21) {
                    break;
                }
                cout << "카드를 받으시겠습니까? (y/n): \n";
                cin >> choice;
            }

            // 딜러는 17 이상일 때까지 카드를 받음
            while (calculate_HandValue(dealerHand) < 17 && deckIndex < deck.size()) {
                dealerHand.push_back(deck[deckIndex]);
                cout << "[딜러]가 받은 카드 숫자 : " << deck[deckIndex]<< "\n" << endl;
                deckIndex++;
            }

            cout << "딜러 손패: " << calculate_HandValue(dealerHand) << endl;

            // 결과 출력
            print_Result(calculate_HandValue(playerHand), calculate_HandValue(dealerHand));
        }
        else if (continue_num == 3) {
            explain_Rule();
        }
        else if (continue_num == 2) {
            cout << "안녕히 가십시오 \n" << endl;
        }
    } while (continue_num != 2);

    return 0;
}