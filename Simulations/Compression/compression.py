
# %%
import numpy as np
import matplotlib.pyplot as plt

# %%
def db2lin(x):
    return 10**(x / 20)

def lin2db(x):
    return 20 * np.log10(np.abs(x) + 1.0e-24)
    

def saturate_db(x_db, db_plus):
    window = 2 * db_plus if db_plus > 0 else -1000
    y_db = np.zeros_like(x_db)
    for idx, x_val in enumerate(x_db):
        y_val = x_val + db_plus
        if x_val >= -window:
            y_val = np.log(x_val + window + 1) - db_plus
        
        y_db[idx] = y_val
    
    return y_db

def saturate(x, db_plus):
    sign = np.sign(x)
    x_db = lin2db(x)
    y_db = saturate_db(x_db, db_plus)
    y = db2lin(y_db) * sign
    return y

# %%
x = np.linspace(-18, 6)
# x = np.linspace(-13, -11)

for db in [0, 1, 2, 3, 4, 5, 6]:
    plt.plot(x, saturate_db(x, db), label=f'Compression Amount: {db} dB')

plt.legend()
plt.xlabel('Input Level [dB]')
plt.ylabel('Output Level [dB]')
plt.title('Tape Compression Characteristic Curves')
plt.grid()
plt.savefig('compression_curves.png')
plt.show()

# %%
# x = np.linspace(-2, 2)

# for db in [0, 1, 2, 3, 4, 5, 6]:
#     plt.plot(x, saturate(x, db))

# plt.grid()

# %%
