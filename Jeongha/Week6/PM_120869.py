def solution(spell, dic):
    answer = 2
    length_of_spell = len(spell)

    # 10
    for word in dic:
        check = [False] * length_of_spell

        # 10
        for letter in word:
            for i in range(length_of_spell):
                if letter == spell[i]:
                    check[i] = True

        if not False in check:
            answer = 1
            return answer

    return answer