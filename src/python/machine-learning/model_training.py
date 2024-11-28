from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score, confusion_matrix
from sklearn.model_selection import cross_val_score

import numpy as np
import seaborn as sns
import matplotlib.pyplot as plt

# Flatten lattices for ML model
data = np.load('data/labeled_lattices.npz', allow_pickle=True)
print("Lattice shape: ", data['lattices'].shape)
print("Labels shape: ", data['labels'].shape)  

X = np.array([lattice.flatten() for lattice in data['lattices']])
y = data['labels']

# Split data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Train a classifier
clf = RandomForestClassifier()
clf.fit(X_train, y_train)

# Evaluate
y_pred = clf.predict(X_test)
print("Accuracy:", accuracy_score(y_test, y_pred))

cm = confusion_matrix(y_test, y_pred)
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', xticklabels=['Low Temp', 'High Temp'], yticklabels=['Low Temp', 'High Temp'])
plt.xlabel('Predicted')
plt.ylabel('True')
plt.title('Confusion Matrix')
plt.show()

scores = cross_val_score(clf, X, y, cv=5)
print("Cross-validation scores:", scores)
print("Mean cross-validation score:", scores.mean())

# Assuming a 20x20 lattice
lattice_shape = (100, 100)
reshaped_importance = clf.feature_importances_.reshape(lattice_shape)

import matplotlib.pyplot as plt
plt.imshow(reshaped_importance, cmap='hot', interpolation='nearest')
plt.colorbar(label='Feature Importance')
plt.title('Feature Importance Heatmap')
plt.show()