import random
import itertools


def greedy(tasks):
    # tasks: list of (a,d)
    tasks_sorted = sorted(tasks, key=lambda x: x[0])
    t = 0
    score = 0
    for a,d in tasks_sorted:
        t += a
        score += d - t
    return score


def brute(tasks):
    best = None
    for perm in itertools.permutations(tasks):
        t = 0
        s = 0
        for a,d in perm:
            t += a
            s += d - t
        if best is None or s > best:
            best = s
    return best


def random_test(iterations=200):
    for it in range(iterations):
        n = random.randint(1,8)
        tasks = [(random.randint(1,10), random.randint(1,10)) for _ in range(n)]
        e = brute(tasks)
        g = greedy(tasks)
        if e != g:
            print('Mismatch', tasks)
            print('brute:', e, 'greedy:', g)
            return
    print('All tests passed')

if __name__ == '__main__':
    random.seed(2)
    random_test(1000)
