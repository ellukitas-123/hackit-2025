def get_element(nums, k , search):
    ocurrencias = 0 
    i = 0
    while (i < len(nums) and ocurrencias < k):
        if (nums[i] == search):
            ocurrencias += 1
        i += 1
    if (ocurrencias == k):
        return i
    else:
        return 0

if __name__ == "__main__":
    while True:
        try:
            size, casos = input().split(" ")
        except:
            exit(0)
        size = int(size)
        casos = int(casos)
        arr = input()
        nums = []
        out = []
        for num in arr.split(" "):
            nums += [int(num)]
        for i in range(casos):
            ocurrencia, valor = input().split(" ")
            ocurrencia = int(ocurrencia)
            valor = int(valor)
            out += [get_element(nums, ocurrencia, valor)]
        for sol in out:
            print(sol)
