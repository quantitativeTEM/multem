function [atoms] = center_specimen(atoms, lx, ly, lz)
atoms(:, 3) = atoms(:, 3) - min(atoms(:, 3));
atoms(:, 4) = atoms(:, 4) - min(atoms(:, 4));
atoms(:, 5) = atoms(:, 5) - min(atoms(:, 5));
lxs = 0.5*(lx-max(atoms(:, 3)));
lys = 0.5*(ly-max(atoms(:, 4)));
lzs = 0.5*(lz-max(atoms(:, 5)));
atoms(:, 3) = atoms(:, 3) + lxs;
atoms(:, 4) = atoms(:, 4) + lys;
atoms(:, 5) = atoms(:, 5) + lzs;