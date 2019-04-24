import numpy as np


def relu(x):
    if isinstance(x, list):
        x = np.array(x)
    if isinstance(x, np.ndarray):
        x = x.copy()
        x[np.where(x <= 0)] = 0
        return x
    else:
        return 0 if x <= 0 else x


def softmax(x):
    if isinstance(x, list):
        x = np.array(x)
    if isinstance(x, np.ndarray):
        x = np.exp(x)
        if len(x.shape) == 1:
            return x / np.sum(x)
        else:
            return x / np.sum(x, axis=1)[:, np.newaxis]
    else:
        raise TypeError('softmax() takes in a list or numpy.ndarray')


def logistic(x):
    return (np.exp(x*-1) + 1)**-1


def predict(x, coefs, intercepts):
    for i in range(len(coefs) - 1):
        x = relu(x @ coefs[i] + intercepts[i])
    x = softmax(x @ coefs[-1] + intercepts[-1])
    return x
