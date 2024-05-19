import numpy as np
import os
#import matplotlib.pyplot as plt


def check_multiply() -> None:
    """
    Функция для верификации результатов вычислений

    :return: None
    """
    script_dir = os.path.dirname(os.path.abspath(__file__))
    neighbor_folder_path = os.path.join(script_dir, "data")
    with open(os.path.join(neighbor_folder_path, "check.txt"), "w") as f:
        for size in [100, 250, 500, 750, 1000]:
            if np.array_equal(np.dot(*[np.loadtxt(os.path.join(neighbor_folder_path, f'{name}Matrix_{size}.txt')) \
                for name in ['first', 'second']]), np.loadtxt(os.path.join(neighbor_folder_path, f'resultMatrix_{size}.txt'))):
                f.write(f'Размеры {size} совпадают!\n')
            else:
                f.write(f'Размеры {size} не совпадают!\n')


if __name__ == '__main__':
    check_multiply()