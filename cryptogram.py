from collections import Counter
import re


def count_total(s):
    return sum(1 for char in s if char.isalpha())


def count_blank(s):
    return s.count("_")


def count_unknown(ans, ques):
    letters_in_ques = re.sub(r"[^a-zA-Z]", "", ans)
    # 统计ques中每个字母的出现次数
    counter1 = Counter(letters_in_ques)
    set2 = set(ques)
    # 统计ans中那些不在ques中的字母的总个数
    total_count = sum(count for letter, count in counter1.items() if letter not in set2)
    return total_count


def count_ukvariety(s, t):
    a = set(char.lower() for char in s if char.isalpha())
    return t - len(a)


def count_tvariety(s):
    unique_letters = set(char.lower() for char in s if char.isalpha())
    return len(unique_letters)


def calculate_difficulty(
    total, blank, unknown, unknown_variety, total_variety, ques, w1=0.5, w2=0.4, w3=0.1
):
    # 确保参数合理
    if total == 0 or total_variety == 0:
        return "Invalid input: Total and Total Variety must be greater than 0."
    # 计算各个部分的比例
    blank_ratio = blank / total
    unknown_ratio = unknown / total
    variety_ratio = unknown_variety / total_variety

    # 综合难度评分
    difficulty_score = (w1 * blank_ratio) + (w2 * unknown_ratio) + (w3 * variety_ratio)

    # 限制评分范围在 0-1
    return max(0.0, min(1.0, difficulty_score))


def line_count(file_path):
    """
    读取文件并返回文件的行数。
    """
    with open(file_path, "r", encoding="utf-8") as file:
        # 使用 sum 和 generator 表达式来计算行数
        line_count = sum(1 for _ in file)

    return line_count


def file_read(file_path,start):
    """
    逐行流式读取文件内容，每次分别读取一行奇数行和一行偶数行，并直接处理输出。
    """
    ans = ""
    ques = ""
    count = 0
    with open(file_path, "r", encoding="utf-8") as file:
        for _ in range(start - 1):
            file.readline()

        while True:
            odd_line = file.readline().strip()  # 读取奇数行
            even_line = file.readline().strip()  # 读取偶数行
            count += 2

            if not odd_line:  # 文件结束
                break
            ans += odd_line + "\n"
            if even_line:
                ques += even_line + "\n"
            if count % 2 == 0:
                return ans.strip(), ques.strip()

start=1
file_path = "q&a.txt"  # 文件路径
lines = line_count(file_path)
n = lines // 2
for i in range(n):
    ans, ques = file_read(file_path,start)
    total = count_total(ans)  # 字母总数
    blank = count_blank(ques)  # 空格数量
    unknown = count_unknown(ans, ques)  # 未知字母数量
    total_variety = count_tvariety(ans)  # 总字母种类数
    unknown_variety = count_ukvariety(ques, total_variety)  # 未知字母种类
    print("奇数行内容 (ans):", ans)
    print("偶数行内容 (ques):", ques)
    print(f"total:{total}")
    print(f"blank:{blank}")
    print(f"unknown:{unknown}")
    print(f"total_variety:{total_variety}")
    print(f"unknown_variety:{unknown_variety}")
    # 计算难度
    difficulty = calculate_difficulty(
        total, blank, unknown, unknown_variety, total_variety, ques)
    print(f"difficulty:{difficulty:.2f}")
    start+=2
