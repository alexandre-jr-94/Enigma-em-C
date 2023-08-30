/*
 ============================================================================
 Name        : Enigma Machine
 Author      : Alexandre Ciro Andriani Júnior
 Version     : 1.0
 Description : Criptografia
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

void enigmaMachine(char *mensagem, int tamanho, int posRotor1, int posRotor2, int posRotor3)
{
    int rotor1[26] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int rotor2[26] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int rotor3[26] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};

    // Definir a posição inicial dos rotores
    rotor1[0] = posRotor1;
    rotor2[0] = posRotor2;
    rotor3[0] = posRotor3;

    for (int i = 0; i < tamanho; i++)
    {
        if ((mensagem[i] >= 'A' && mensagem[i] <= 'Z') || (mensagem[i] >= 'a' && mensagem[i] <= 'z'))
        {

            if (mensagem[i] >= 'a' && mensagem[i] <= 'z')
            {
                mensagem[i] = mensagem[i] - 'a' + 'A';
            }
        }

        posRotor1 = (posRotor1 + 1) % 26;
        if (posRotor1 == 0)
        {
            posRotor2 = (posRotor2 + 1) % 26;
            if (posRotor2 == 0)
            {
                posRotor3 = (posRotor3 + 1) % 26;
            }
        }

        int posCaractere = mensagem[i];

        // Realizar a substituição através dos rotores
        posCaractere = rotor1[posCaractere];
        posCaractere = rotor2[posCaractere];
        posCaractere = rotor3[posCaractere];

        posCaractere = (posCaractere + posRotor1) % 26;
        posCaractere = (posCaractere + posRotor2) % 26;
        posCaractere = (posCaractere + posRotor3) % 26;

        mensagem[i] = posCaractere + 'A';
        printf("Mensagem sendo criptografada: %s\n", mensagem);
    }
    printf("Mensagem criptografada: %s\n", mensagem);
}

int main()
{
    char mensagem[100];
    int tamanho;
    int posRotor1, posRotor2, posRotor3;

    // Solicitar a posição inicial dos rotores
    printf("Digite o número de posição inicial para o rotor 1 (0-25): ");
    scanf_s("%d", &posRotor1);
    printf("Digite o número de posição inicial para o rotor 2 (0-25): ");
    scanf_s("%d", &posRotor2);
    printf("Digite o número de posição inicial para o rotor 3 (0-25): ");
    scanf_s("%d", &posRotor3);

    // Solicitar a mensagem a ser criptografada
    printf("Digite a mensagem a ser criptografada (em letras maiúsculas): ");
    scanf_s(" %[^\n]", mensagem);

    tamanho = strlen(mensagem);

    // Chamar a função para criptografar a mensagem
    enigmaMachine(mensagem, tamanho, posRotor1, posRotor2, posRotor3);

    return 0;
}
