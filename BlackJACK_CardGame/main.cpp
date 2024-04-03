#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// ī�� ���� �ʱ�ȭ�ϴ� �Լ�
void initialize_Deck(vector<int>& deck, int size) {
    for (int i = 0; i < size; ++i) {
        deck.push_back(i % 13 + 1);
    }
}

// ī�带 ���� �Լ�
void shuffle_Deck(vector<int>& deck) {
    for (int i = 0; i < deck.size(); ++i) {
        int randomIndex = rand() % deck.size();
        swap(deck[i], deck[randomIndex]);
    }
}

// ī�� ���� ����ϴ� �Լ� (A�� 1 �Ǵ� 11�� ���)
int calculate_Value(int card) {
    return (card > 10) ? 10 : card;
}

// �÷��̾� �Ǵ� ������ ī�� ���� ����ϴ� �Լ�
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

// ���� ����� ����ϴ� �Լ�
void print_Result(int playerTotal, int dealerTotal) {
    if (playerTotal > 21) {
        cout << "�÷��̾��� ���ڰ� 21�� �Ѿ����ϴ�! ������ �¸��Դϴ�.\n\n" << endl;
    }
    else if (dealerTotal > 21) {
        cout << "������ ���ڰ� 21�� �Ѿ����ϴ�. �÷��̾��� �¸��Դϴ�.\n\n" << endl;
    }
    else if (playerTotal > dealerTotal) {
        cout << "�÷��̾��� �¸�! �й��ϼ̽��ϴ�.\n\n" << endl;
    }
    else if (playerTotal < dealerTotal) {
        cout << "������ �¸�!!!! �й��ϼ̽��ϴ�.\n\n" << endl;
    }
    else {
        cout << "���º�!" << endl;
    }
}

void explain_Rule() {
    std::cout << "************************************************ �� ���� ************************************************\n";
    std::cout << "������ ī���� ���� �� �ϳ���, ������ �÷��̾ ī�带 �޾� ����� ���� 21�� ����������� �ϴ� �����Դϴ�.\n";
    std::cout << "�� ī�忡�� ���ڰ� �ο��Ǹ�, ���� ī��� �� ���ڸ�ŭ�� ���� ������, ŷ, ��, ���� ���� 10�� ���� ������, ���̽��� 1 �Ǵ� 11�� ���� �����ϴ�.\n";
    std::cout << "������ ������ ���� �ܰ�� ����˴ϴ�:\n\n";
    std::cout << "1. ������ �÷��̾�� �ڽſ��� ī�带 2�徿 �����ݴϴ�. ���� ������ �� ���� �޸����� �ΰ� �� ���� �����Ͽ� �����ݴϴ�.\n";
    std::cout << "2. �÷��̾�� �ڽ��� ī�带 Ȯ���� ��, �� ���� ī�带 ������(hit) �׸� ������(stop)�� �����մϴ�.\n";
    std::cout << "3. �÷��̾ ī�带 �� �̻� ���� �ʴ´ٸ�, ������ �ڽ��� ī�带 �����մϴ�. ������ 17 �̻��� ���ڰ� �� ������ ī�带 ��� �޽��ϴ�.\n";
    std::cout << "4. ������ �÷��̾��� ���ڸ� ���Ͽ� ���и� �����մϴ�. 21�� ����� ���ڸ� ���� ���� �¸��ϸ�, 21�� �ʰ��ϸ� �й��մϴ�. ������ ��� ���ϴ�.\n";
    std::cout << "5. �÷��̾ 21�� ����� ���ڸ� ������ �����鼭 ���ÿ� ������ 21�� ����� ���ڸ� ������ ���� �ʴٸ�, �÷��̾ �̱�ϴ�.\n\n\n";
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
        cout << "�̿��ϰ��� �ϴ� �޴��� ���ڸ� �Է��ϼ���\n" << endl;
        cout << "1. ���ӽ��� \n2. �������� \n3. �꼳��\n\n" << endl;
        cin >> continue_num;

        if (continue_num == 1) {
            srand(time(0)); // ���� �õ� ����

            const int deckSize = 52;
            vector<int> deck;
            initialize_Deck(deck, deckSize);
            shuffle_Deck(deck);

            vector<int> playerHand;
            vector<int> dealerHand;
            int deckIndex = 4;

            // �ʱ� �� ���� ī�带 ������
            playerHand.push_back(deck[0]);
            dealerHand.push_back(deck[1]);
            playerHand.push_back(deck[2]);
            dealerHand.push_back(deck[3]);

            cout << "�÷��̾ ���� ī��: |"<< deck[0] <<", "<< deck[2] << "|    ī�� �� : **" << calculate_HandValue(playerHand) << endl;
            cout << "������ ī�� ��:       |" << deck[1] << ", " << deck[3] << "|    ī�� �� : **" << calculate_HandValue(dealerHand)<< "\n" << endl;

            // �÷��̾ �� �̻� ī�带 ������ ����
            char choice;
            cout << "ī�带 �����ðڽ��ϱ�? (y/n): ";
            cin >> choice;

            while (choice == 'y' || choice == 'Y') {
                playerHand.push_back(deck[deckIndex]);
                cout << "[�÷��̾�]�� ���� ī�� ���� : " << deck[deckIndex] << endl;
                deckIndex++;
                cout << "�÷��̾��� ���а�: " << calculate_HandValue(playerHand)<< "\n" << endl;
                if (calculate_HandValue(playerHand) > 21) {
                    break;
                }
                cout << "ī�带 �����ðڽ��ϱ�? (y/n): \n";
                cin >> choice;
            }

            // ������ 17 �̻��� ������ ī�带 ����
            while (calculate_HandValue(dealerHand) < 17 && deckIndex < deck.size()) {
                dealerHand.push_back(deck[deckIndex]);
                cout << "[����]�� ���� ī�� ���� : " << deck[deckIndex]<< "\n" << endl;
                deckIndex++;
            }

            cout << "���� ����: " << calculate_HandValue(dealerHand) << endl;

            // ��� ���
            print_Result(calculate_HandValue(playerHand), calculate_HandValue(dealerHand));
        }
        else if (continue_num == 3) {
            explain_Rule();
        }
        else if (continue_num == 2) {
            cout << "�ȳ��� ���ʽÿ� \n" << endl;
        }
    } while (continue_num != 2);

    return 0;
}