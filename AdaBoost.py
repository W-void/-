from sklearn.tree import DecisionTreeClassifier
import numpy as np
import pandas as pd
from sklearn.metrics import accuracy_score
from sklearn.linear_model import LogisticRegression
from sklearn.preprocessing import scale
from sklearn.model_selection import train_test_split


def adaboost(x, y, n_estimators=40):
    ada = []
    (m, n) = x.shape
    y = y.flatten()
    y[y == 0] = -1
    f = np.zeros_like(y)
    d = np.ones((m)) / m
    for i in range(n_estimators):
        # dt = DecisionTreeClassifier(max_depth=depth)
        # clf = LogisticRegression()
        # clf.fit(x, y, d)
        clf = DecisionTreeClassifier(max_depth=1)
        idx = np.random.choice(m, m, p=d)
        tmp_x = x[idx]
        tmp_y = y[idx]
        clf.fit(tmp_x, tmp_y)
        y_pred = clf.predict(x)
        e = np.sum(d * (y_pred != y))
        alpha = 0.5 * np.log2((1-e) / e)
        d = d * np.exp(-alpha * y * y_pred)
        d = d / np.sum(d)
        ada.append([clf, alpha])
        f += alpha * y_pred
    return f > 0, ada

bone_data = pd.read_csv('all_bone_info_df.csv')
features_list = list(bone_data.columns)[1:]
features_list.remove('class_id')
features_list.remove('target')

x = bone_data[features_list]
y = bone_data[['target']]

x = scale(x)
y_pred, _ = adaboost(x, y.values)
print(accuracy_score(y, y_pred))
